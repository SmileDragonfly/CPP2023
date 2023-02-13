#include <regex>
#include <fstream>
#include <iostream>
#include "Utils.h"

struct TLine {
	int iLineStart;
	int lLineEnd;
};

int main() {
	std::string sFileName = "TestFile.txt";
	std::ifstream file(sFileName, std::ifstream::binary);
	char* pFileBuf = nullptr;
	char CR = '\r';
	if (file.is_open())
	{
		long long nFileSize = file.tellg();
		file.seekg(0, std::ios_base::end);
		nFileSize = file.tellg() - nFileSize;
		std::cout << "File size: " << nFileSize << std::endl;

		file.seekg(0, std::ios_base::beg);
		pFileBuf = new char[nFileSize];
		file.read(pFileBuf, nFileSize);
		if (file)
			std::cout << "All characters read successfully.";
		else
			std::cout << "Error: only " << file.gcount() << " could be read";
		file.close();

		// Get all lines of file
		std::vector<std::vector<char>> vLines;
		FindAllLines(pFileBuf, nFileSize, vLines);
		std::string sPattern("TRANSACTION START");
		for (int i = 0; i < vLines.size(); i++)
		{
			if (SearchPatternInLine(vLines[i], sPattern))
			{
				std::cout << "Index: " << i << std::endl;
				break;
			}
		}
	}
	char c;
	std::cin >> c;
}
