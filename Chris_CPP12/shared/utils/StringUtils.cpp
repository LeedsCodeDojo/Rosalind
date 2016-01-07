#include "Common.h"

/// Add a number of spaces to a string stream
void Indent(std::ostringstream& str, uint32_t index)
{
    for (unsigned int i = 0; i < index; i++)
    {
        str << " ";
    }
}

void Tab(std::ostringstream& str, uint32_t tab, uint32_t tabSize)
{
    std::string text = str.str();

    std::size_t pos = text.rfind("\n");
    if (pos == std::string::npos)
    {
        pos = text.length();
    }
    else
    {
        pos++;
    }

    int currentOffset = (int)(text.length() - pos);
    int newOffset = tabSize * tab;

    if (currentOffset >= newOffset)
    {
        return;

    }

    while (currentOffset < newOffset)
    {
        str << " ";
        currentOffset++;
    }
}

std::string Tail(std::string const& source, uint32_t length)
{
    if (length >= source.length())
    {
        return source;
    }

    std::string ret;
    ret.resize(length);
    memcpy(&ret[0], &source[source.length() - length], length);

    return source;
}

std::vector<std::string> Split(std::string s, const char delimiter)
{
    Trim(s);
    size_t start = 0;
    size_t end = s.find_first_of(delimiter);

    std::vector<std::string> output;

    while (end <= std::string::npos)
    {
        output.emplace_back(Trim(s.substr(start, end - start)));

        if (end == std::string::npos)
            break;

        start = end + 1;
        end = s.find_first_of(delimiter, start);
    }

    return output;
}

std::string GetFileName(const std::string& strPath)
{
    size_t iLastSeparator = 0;
    return strPath.substr((iLastSeparator = strPath.find_last_of("\\/")) != std::string::npos ? iLastSeparator + 1 : 0);// , strPath.size() - strPath.find_last_of("."));
}

std::string RemoveExtension(const std::string& strPath)
{
    size_t iLastSeparator = 0;
    return strPath.substr(0, (iLastSeparator = strPath.find_last_of(".")) != std::string::npos ? iLastSeparator : strPath.length());// , strPath.size() - strPath.find_last_of("."));
}

std::string ReplaceAll(std::string str, const std::string& from, const std::string& to)
{
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

std::string ReplaceFirst(std::string str, const std::string& from, const std::string& to)
{
    size_t start_pos = 0;
    if ((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
    }
    return str;
}

bool CompareLowerCase(std::string const& l, std::string const& r)
{
    return l.size() == r.size()
        && equal(l.cbegin(), l.cend(), r.cbegin(),
            [](std::string::value_type l1, std::string::value_type r1)
    { return toupper(l1) == toupper(r1); });
}

void ToLowerInPlace(std::string& s)
{
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
}


