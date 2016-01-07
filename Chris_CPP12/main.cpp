#include "Common.h"

#include "DNA.h"
#include "RNA.h"
#include "REVC.h"
#include "GC.h"
#include "FIB.h"
#include "PROT.h"
#include "HAMM.h"
using namespace std;

std::map<std::string, RosalindFunc_t> mapNameFunc;

TCLAP::ValueArg<std::string> problemArg("p", "problem", "Problem to run", true, "DNA", "string");
TCLAP::ValueArg<std::string> dirArg("d", "data", "Data path", true, "data", "string");

void GlobalReg(const std::string& name, RosalindFunc_t func)
{
    mapNameFunc[name] = func;
}

std::string GetInputPath()
{
    return dirArg.getValue() + "/rosalind_" + problemArg.getValue() + ".txt";
}

std::string GetOutputPath()
{
    return dirArg.getValue() + "/rosalind_" + problemArg.getValue() + "_out.txt";
}

std::string ReadInput()
{
    std::ifstream t(GetInputPath());
    if (!t.is_open())
    {
        std::cerr << "File not found: " << GetInputPath() << std::endl;
        return std::string();
    }
    return std::string((std::istreambuf_iterator<char>(t)),
        std::istreambuf_iterator<char>());
}

std::shared_ptr<Fasta> ReadInputFasta()
{
    return std::make_shared<Fasta>(GetInputPath());
}

void WriteOutput(const std::string& out)
{
    std::ofstream t(GetOutputPath());
    if (!t.is_open())
    {
        std::cerr << "Couldn't write: " << GetOutputPath() << std::endl;
        return;
    }

    t << out;

    std::cout << "Wrote: " << std::endl << out << std::endl;
}

int main(int argc, char **argv)
{
    DNA_Register();
    RNA_Register();
    REVC_Register();
    GC_Register();
    FIB_Register();
    PROT_Register();
    HAMM_Register();

    try
    {
        // Parse the command line
        TCLAP::CmdLine cmd("Rosalind", ' ', "1.0");
        cmd.setExceptionHandling(false);

        cmd.add(problemArg);
        cmd.add(dirArg);

        // Parse the argv array.
        cmd.parse(argc, argv);

        auto itr = mapNameFunc.find(problemArg.getValue());
        if (itr == mapNameFunc.end())
        {
            std::cerr << "Error: " << problemArg.getValue() << " problem not found!" << std::endl;
        }
        else
        {
            itr->second();
        }
    }
    catch (TCLAP::ArgException& e)
    {
        std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl;
    }

    system("pause");
        
    return 0;
}

