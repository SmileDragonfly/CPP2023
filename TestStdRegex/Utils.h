#pragma once
#include <vector>
#include <string>
#include <Windows.h>

struct TTransaction {
	int iLineStart;
	int lLineEnd;
	FILETIME time;
};


void FindAllLines(char* pBuff, long long lLength, std::vector<std::vector<char>>& vLines);
bool SearchPatternInLine(std::vector<char> vLine, std::string sPattern);
void GetTransactionsInfo(std::vector<std::vector<char>> vLines, 
	std::string sPatternStart, 
	std::string sPatternEnd, 
	std::string sPatternTime,
	std::vector<TTransaction>& vTransactions);