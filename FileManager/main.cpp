#include <iostream>
#include "file_manager.h"
using std::cout;
using std::endl;
int main(int argc, char const* argv[])
{
    try
    {
        file_manager myFile;
        string data = myFile.getData("file_manager.cpp");
        string from("std");
        string to("hello");
        cout << "The file start:" << endl;
        cout << data << endl
            << "the file end" << endl;
        myFile.replaceAll(data, from, to);
        cout << "The replace start:" << endl;
        cout << data << endl
            << "the replace end" << endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
