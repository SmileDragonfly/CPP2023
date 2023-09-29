// Challenges.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// pseudo code:
// max1 = p[0]
// max2 = p[1]
// for p[i] in p:
//   if p[i] > max1 || p[i] > max2:
//      if max1 > max2:
//          max2 = [pi]
//      else
//          max1 = p[i]
// return max1 + max2
//  

int FindSumOfTwoLargestNumber(int* pData, int length) {
    if (length < 2) {
        throw std::runtime_error("Invalid length");
        return 0; 
    }
    int max1 = pData[0];
    int max2 = pData[1];
    for (int i = 0; i < length; i++) {
        if ((pData[i] > max1) || (pData[i] > max2)) {
            if (max1 > max2) {
                max2 = pData[i];
            }
            else {
                max1 = pData[i];
            }
        }
    }
    return max1 + max2;
}

int main()
{
    std::cout << "Hello World!\n";
    int* pData = new int[8] {3,5,35,6,7,2,200,1};
    try {
        std::cout << FindSumOfTwoLargestNumber(pData, 6);
    }
    catch (std::exception e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    int nGet = std::getchar();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
