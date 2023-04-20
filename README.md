# file_manager

## 项目初衷

​	由于经常需要写一个读写文件的操作，虽然难度不高，但是细节总是很多，出错的概率很大。所以决定写一个工具类，来一步一步集成文件和字符串操作中遇到的问题解决方案。

## 接口说明

​	目前该工具类拥有两个接口：

* `getData`：读取文件，返回文件内容的string
* `replaceAll`：将字符串中的特征子串替换为指定子串
* `parseFileToWords`：将string分割成单词数组

## 使用示例

​	这段代码展示了如何读取一个文件，并替换其中的指定子串，最后输出到另一个文件中。

```C++
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

```

