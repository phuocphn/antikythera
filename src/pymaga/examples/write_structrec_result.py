import pymaga
import os
import glob

from loguru import logger


def recognize(circuit: pymaga.Circuit, fname) -> pymaga.StructRecResult:
    print("[B] Structure Result".center(100, "*"))
    structRec_inst = pymaga.StructRec()
    structureLib: pymaga.StructRec = structRec_inst.createStructureLibrary(
        "StructRec/xml/AnalogLibrary.xml",
        "examples/StructureRecognition/deviceTypes.xcat",
    )
    structureResult = structureLib.recognize(circuit)
    print(structureResult)
    structureResult.writeXml(fname)
    print("[E] Structure Result".center(100, "*"))


def process(fname):
    with open(fname, "r") as f:
        netlist_data = "".join(f.readlines()[1:-2])

    netlist_data = netlist_data.replace("sourceNmos", "gnd!")
    netlist_data = netlist_data.replace("sourcePmos", "vdd!")

    updated_netlist = f"""
.GLOBAL vdd! gnd!

.TEMP 25.0
.OPTION
+    ARTIST=2
+    INGOLD=2
+    PARHIER=LOCAL
+    PSF=2

** Library name: CascodeSymmetricalCMOSOTA
** Cell name: cascodeSymmetricalCMOSOTA
** View name: schematic
{netlist_data.strip()}
.END
""".strip()

    new_circuit_fname = os.path.join(
        "outputs/TopologyGen_29_12_2024/SingleOutputOpAmps/",
        os.path.basename(fname),
    )
    partitioning_fname = os.path.join(
        "outputs/TopologyGen_29_12_2024/StructRecResult/",
        os.path.basename(fname).replace(".ckt", ".xml"),
    )
    with open(new_circuit_fname, "w") as f:
        f.write(updated_netlist)

    circuit = pymaga_io.readInCircuit(
        circuit_filepath=new_circuit_fname,  # "examples/StructureRecognition/input.ckt",
        supplynet_filepath="examples/StructureRecognition/supplyNets.xcat",
        mapping_filepath="examples/StructureRecognition/HSpiceMapping.xcat",
        devicetype_filepath="examples/StructureRecognition/deviceTypes.xcat",
    )
    recognize(circuit, partitioning_fname)

if __name__ == "__main__":
    pymaga_io = pymaga.IOCore()

    for fname in glob.glob(
        "outputs/TopologyGen_24_12_2024/SingleOutputOpAmps/*"
    ):
        process(fname)
