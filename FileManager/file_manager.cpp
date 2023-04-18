#include "file_manager.h"

file_manager::file_manager() {}

string file_manager::getData(string filename) throw(std::ifstream::failure)
{
	std::ifstream streamReader(filename, std::ios::binary);
	if (!streamReader.is_open())
		throw std::ifstream::failure("file couldn't open");
	streamReader.seekg(0, std::ios::end);		//游标移到文件结尾
	std::streamoff filesize = streamReader.tellg();		//获取游标当前位置 - 文件开始位置，此处为文件大小
	char* _data = new char[filesize];					//分配内存
	streamReader.seekg(0, std::ios::beg);		//跳转回开始
	streamReader.read(_data, filesize);		//读取文件
	streamReader.close();
	string data(_data);
	delete[] _data;
	return std::move(data);
}

string& file_manager::replaceAll(string& context, const string& from, const string& to)
{
	size_t lookHere = 0;
	size_t foundHere;
	while ((foundHere = context.find(from, lookHere)) != string::npos)		// find from lookHere
	{																					// to avoid the string
		context.replace(foundHere, from.size(), to);					//"to" is the substr
		lookHere = foundHere + to.size();												// of "from"
	}
	return context;
}
