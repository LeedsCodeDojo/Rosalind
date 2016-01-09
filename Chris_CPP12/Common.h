#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <functional>
#include <tclap/CmdLine.h>
#include <StringUtils.h>
#include <memory>

#include "Fasta.h"

typedef std::function<void()> RosalindFunc_t;
void GlobalReg(const std::string& name, RosalindFunc_t func); 

std::string ReadInput();
std::shared_ptr<Fasta> ReadInputFasta();

void WriteOutput(const std::string& text);

#define DECLARE_PROBLEM(name) void name(); void name##_Register();

#define MAKE_PROBLEM(name)                      \
DECLARE_PROBLEM(name)                           \
void name##_Register()                          \
{                                               \
    GlobalReg(#name, RosalindFunc_t(name));     \
}                                               \
void name()

