#pragma once
#include <string>

class Utils
{
public:
	static bool CheckARegex(std::string sData, std::string sRegex);
	static bool ReplaceAGroup(std::string sData, std::string sRegex);
};

