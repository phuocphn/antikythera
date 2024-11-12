/**************************************************************************************************
 *  Main authors:
 *     Inga Abel <inga.abel@tum.de>, 
 *	   Maximilian Neuner <maximilian.neuner@tum.de>, 
 *     Michael Eick <michael.eick@tum.de>
 *
 * 
 *  Copyright (C) 2021
 *  Chair of Electronic Design Automation
 *  Univ.-Prof. Dr.-Ing. Ulf Schlichtmann
 *  TU Muenchen
 *  Arcisstrasse 21
 *  D-80333 Muenchen
 *  Germany
 *
 *  This file is part of acst, a analog circuit analysis, sizing and synthesis enviroment:
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the
 *  "Software"), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so, subject to
 *  the following conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 *  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 *  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 *  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *************************************************************************************************/


#ifndef AUTOMATICSIZING_LOCALOPTIONS_H_
#define AUTOMATICSIZING_LOCALOPTIONS_H_

#include "AutomaticSizing/incl/CircuitInformationFiles/CircuitInformationFile.h"
#include "HSpice/incl/InputFile/InputFile.h"

#include "StructRec/incl/LibraryFile/LibraryFile.h"
#include <string>

#include "Partitioning/incl/LocalOptions.h"
#include "AutomaticSizing/incl/CircuitInformationFiles/TechnologieFileSHM.h"
#include "AutomaticSizing/incl/CircuitInformationFiles/TechnologieFileEKV.h"


namespace HSpice {
	class DeviceLineMapper;

}

namespace Core{
	class Circuit;
	class DeviceTypeRegister;
}


namespace AutomaticSizing {



	class LocalOptions : public Partitioning::LocalOptions
    {
    public:
        LocalOptions(const std::string& description);

        CircuitInformationFile getCircuitInformationFile() const;
        TechnologieFileEKV getTechnologieFileEKV() const;
        TechnologieFileSHM getTechnologieFileSHM() const;

        std::string getTransistorModel() const;
        std::string getScaling() const;
        int getRuntime() const;



    private:
        static const std::string XML_TECHNOLOGIE_FILE_OPTION_;
        static const std::string XML_TECHNOLOGIE_FILE_DESCRIPTION_;
        static const std::string XML_CIRCUIT_INFORMATION_FILE_OPTION_;
        static const std::string XML_CIRCUIT_INFORMATION_FILE_DESCRIPTION_;
        static const std::string TRANSISTOR_MODEL_DESCRIPTION_;
        static const std::string TRANSISTOR_MODEL_OPTION_;
        static const std::string SCALING_OPTION_;
        static const std::string SCALING_DESCRIPTION_;
        static const std::string RUNTIME_OPTION_;
        static const std::string RUNTIME_DESCRIPTION_;


        void initialize();
    };


}

#endif
