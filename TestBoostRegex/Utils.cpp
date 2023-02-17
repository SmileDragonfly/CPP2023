#include "Utils.h"
#include "boost/regex.hpp"

bool Utils::CheckARegex(std::string sData, std::string sRegex)
{
    boost::regex reg(sRegex);
    if (boost::regex_search(sData, reg))
    {
        return true;
    }
    return false;
}
