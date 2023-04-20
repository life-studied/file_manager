# file_manager

## 项目初衷

​	由于经常需要写一个读写文件和处理字符串的操作，虽然难度不高，但是细节总是很多，出错的概率很大。所以决定写一个工具类，来一步一步集成文件和字符串操作中遇到的问题解决方案。

## 接口说明

​	目前该工具类拥有三个接口：

* `getData`：读取文件，返回文件内容的string
* `replaceAll`：将字符串中的特征子串替换为指定子串
* `parseFileToWords`：将string分割成单词数组

## 使用示例

### 示例1

​	这段代码展示了如何读取一个文件，并替换其中的指定子串，最后输出到另一个文件中。

​	使用接口：

* getData
* replaceAll

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

### 示例2

​	该示例展示了如何解析文件并分割为单词，并判断是否单词是否是回文字符串

​	使用接口：

* getData
* parseFileToWords

```C++
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
```

