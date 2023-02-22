#include "Utils.h"
#include "boost/regex.hpp"
#include <iostream>

bool Utils::CheckARegex(std::string sData, std::string sRegex)
{
    boost::regex reg(sRegex);
    if (boost::regex_search(sData, reg))
    {
        return true;
    }
    return false;
}

bool Utils::ReplaceAGroup(std::string sData, std::string sRegex)
{
    std::string subject("DATE:22-07-20 04:44:34  ATM_ID:80000301");

    std::string result1, result2, result3, result4;
    std::string result5;

    // regex object
    std::string s("(?<PREFIX>ATM_ID:)(?<ATMID>.{8})");
    boost::regex re(s);
   
    // $2 contains, 2nd capturing group which is (.*) means
    // string after "geeks" which is "forgeeks". hence
    // the match(geeksforgeeks) will be replaced by "forgeeks".
    // so the result1 = "its all about forgeeks"
    boost::smatch match;
    if (boost::regex_search(subject, match, re))
    {
        std::cout << "Match:" << match.str() << std::endl;
        std::cout << "Match 0:" << match[0] << std::endl;
        std::cout << "Match 1:" << match[1] << std::endl;
        std::cout << "Match 2:" << match[2] << std::endl;
        std::string sReplace = match[1] + "1232134";
        result1 = boost::regex_replace(subject, re, sReplace);
    } 

    // similarly $1 contains, 1 st capturing group which is
    // "geeks" so the match(geeksforgeeks) will be replaced
    // by "geeks".so the result2 = "its all about geeks".
    result2 = boost::regex_replace(subject, re, "$1");

    // $0 contains the whole match
    // so result3 will remain same.
    result3 = boost::regex_replace(subject, re, "$0");

    // $0 and $& contains the whole match
    // so result3 will remain same
    result4 = boost::regex_replace(subject, re, "$&");

    // Here number of capturing group
    // is 2 so anything above 2
    // will be replaced by nothing.
    result5 = boost::regex_replace(subject, re, "$6");

    std::cout << result1 << std::endl << result2 << std::endl;
    std::cout << result3 << std::endl << result4 << std::endl << result5;

    return false;
}


