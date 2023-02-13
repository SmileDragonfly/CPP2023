#include "Utils.h"
#include <regex>

void FindAllLines(char* pBuff, long long lLength, std::vector<std::vector<char>>& vLines)
{
	long long lStart = 0;
	for (int i = lStart; i < lLength; i++)
	{
		if (pBuff[i] == 13)
		{
			std::vector<char> vLine(&pBuff[lStart], &pBuff[i + 1]);
			vLines.push_back(vLine);
			lStart = i + 1;
		}
	}
}

bool SearchPatternInLine(std::vector<char> vLine, std::string sPattern)
{
	std::regex reg(sPattern);
	std::string sLine(vLine.begin(), vLine.end());
	std::smatch match;
	if (std::regex_search(sLine, match, reg))
	{
		return true;
	}
	return false;
}
