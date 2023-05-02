#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "file_manager.h"
using namespace std;

int main(int argc, char const* argv[])
{
    try
    {
        file_manager fm;
        string fileTxt = fm.getData("main.cpp");
        cout << fileTxt << endl;
        fm.writeData("hello.txt", fileTxt);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
