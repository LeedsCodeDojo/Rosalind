#include "Common.h"

Fasta::Fasta(const std::string& filePath)
{
    std::ifstream file(filePath);
    if (file.is_open())
    {
        FastaEntry entry;

        enum class ParseState { Name, Data };
        ParseState currentState = ParseState::Name;

        auto pushEntry = [&] ()
        {
            if (currentState != ParseState::Name)
            {
                _entries.push_back(entry);
                entry.data.clear();
                entry.description.clear();
                entry.name.clear();

                std::cout << "Entry: " << _entries[_entries.size() - 1].name << std::endl;
                std::cout << "Desc:  " << _entries[_entries.size() - 1].description << std::endl;
                std::cout << "Data:  " << _entries[_entries.size() - 1].data << std::endl << std::endl;
            }
        };

        std::string str;
        while (std::getline(file, str))
        {
            if (str.empty())
            {
                continue;
            }

            if (str[0] == '>')
            {
                pushEntry();
                auto location = GetToken(str, 1);
                
                currentState = ParseState::Data;
                entry.name = Trim(str.substr(location.first, location.second));
                
                auto nextPos = location.first + location.second;
                if (nextPos < str.size())
                {
                    entry.description = Trim(str.substr(nextPos, str.size() - nextPos));
                }
            }
            else
            {
                if (currentState == ParseState::Data)
                {
                    entry.data += Trim(str);
                }
            }
        }

        pushEntry();
    }
}