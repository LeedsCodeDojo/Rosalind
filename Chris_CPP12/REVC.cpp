#include "Common.h"

using namespace std;

MAKE_PROBLEM(REVC)
{
    std::string text = ReadInput();

    std::ostringstream str;
    for (auto itr = text.rbegin(); itr != text.rend(); itr++)
    {
        switch (*itr)
        {
        case 'A':
            str << "T";
            break;
        case 'T':
            str << "A";
            break;
        case 'G':
            str << "C";
            break;
        case 'C':
            str << "G";
            break;
        }
    }

    WriteOutput(str.str());
}


