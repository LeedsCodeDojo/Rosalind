#include "Common.h"
#include "Codon.h"

using namespace std;

MAKE_PROBLEM(PROT)
{
    std::string text = ReadInput();

    // Create a codon mapper
    Codon codonMapper;

    std::ostringstream strOut;

    int groups = text.size() / 3;
    for (auto group = 0; group < groups; group++)
    {
        std::string result = codonMapper.Map(text.substr(group * 3, 3));
        if (result.empty())
        {
            // We are done, or didn't recognize
            break;
        }

        strOut << result;
    }

    WriteOutput(strOut.str());
}


