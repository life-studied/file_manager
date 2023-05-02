#include "file_manager.h"

file_manager::file_manager() {}

string file_manager::getData(const string& filename) throw(std::ifstream::failure)
{
	std::ifstream streamReader(filename, std::ios::binary);
	if (!streamReader.is_open())
		throw std::ifstream::failure("file couldn't open");
	streamReader.seekg(0, std::ios::end);		//游标移到文件结尾
	std::streamoff filesize = streamReader.tellg();		//获取游标当前位置 - 文件开始位置，此处为文件大小
	char* _data = new char[filesize+1];					//分配内存
	streamReader.seekg(0, std::ios::beg);		//跳转回开始
	streamReader.read(_data, filesize);		//读取文件
    _data[filesize] = '\0';
	streamReader.close();
	string data(_data);
	delete[] _data;
	return std::move(data);
}

void file_manager::writeData(const string& filename, const string& txt) throw(std::ofstream::failure)
{
    std::ofstream streamWriter(filename, std::ios::binary);
    if (!streamWriter.is_open())
        throw std::ofstream::failure("file couldn't open");
    const char* data = txt.c_str();
    size_t size = txt.size();
    streamWriter.write(data, size);
    streamWriter.close();
}
