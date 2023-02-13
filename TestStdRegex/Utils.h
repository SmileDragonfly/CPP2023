#pragma once
#include <vector>
#include <string>

void FindAllLines(char* pBuff, long long lLength, std::vector<std::vector<char>>& vLines);
bool SearchPatternInLine(std::vector<char> vLine, std::string sPattern);