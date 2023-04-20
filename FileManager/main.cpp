#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "file_manager.h"
using namespace std;

bool isBString(string testStr)
{
    int size = testStr.size();
    for (size_t i = 0; i < size / 2; i++)
    {
        if (tolower(testStr[i]) == tolower(testStr[size - i] - 1))
            continue;
        return false;
    }
    return true;
}


int main(int argc, char const* argv[])
{
    try
    {
        file_manager fm;
        string fileTxt = fm.getData("main.cpp");
        vector<string> words = fm.parseFileToWords(fileTxt);
        for (const auto& i : words)
            cout << i << " : " << isBString(i) << endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
