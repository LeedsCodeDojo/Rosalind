#pragma once

void Indent(std::ostringstream& str, uint32_t index);
void Tab(std::ostringstream& str, unsigned int tab, uint32_t tabSize = 4);
std::string Tail(std::string const& source, uint32_t length);
std::string GetFileName(const std::string& strPath);
std::string RemoveExtension(const std::string& strPath);
std::string ReplaceAll(std::string str, const std::string& from, const std::string& to);
std::string ReplaceFirst(std::string str, const std::string& from, const std::string& to);
bool CompareLowerCase(std::string const& a, std::string const& b);
void ToLowerInPlace(std::string& s);
    
std::vector<std::string> Split(std::string s, const char delimiter);

// trim from end of string (right)
inline std::string& RTrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}
 
    
inline std::pair<std::string::size_type, std::string::size_type> GetToken(std::string& s, unsigned int offset = 0, const char* t = " \t\n\r\f\v")
{
    std::pair<std::string::size_type, std::string::size_type> ret;
    ret.first = s.find_first_not_of(t, offset);
    if (ret.first == std::string::npos)
    {
        return ret;
    }

    ret.second = s.find_first_of(t, ret.first);
    if (ret.second == std::string::npos)
    {
        ret.second = s.size() - ret.first;
    }
    else
    {
        ret.second = ret.second - ret.first;
    }
    return ret;
}

// trim from beginning of string (left)
inline std::string& LTrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}
    
// trim from both ends of string (left & right)
inline std::string& Trim(std::string& s, const char* t = " \t\n\r\f\v")
{
    return LTrim(RTrim(s, t), t);
}
