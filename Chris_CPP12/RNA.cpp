#include "Common.h"

using namespace std;

MAKE_PROBLEM(RNA)
{
    std::string text = ReadInput();

    std::replace(text.begin(), text.end(), 'T', 'U');

    WriteOutput(text);
}


