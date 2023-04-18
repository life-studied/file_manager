#include "file_manager.h"
#include <fstream>

file_manager::file_manager() {}

string&& file_manager::getData(string filename) throw(std::ifstream::failure)
{
	std::ifstream streamReader(filename, std::ios::binary);
	if (!streamReader.is_open())
		throw std::ifstream::failure("file couldn't open");
	streamReader.seekg(0, std::ios::end);		//�α��Ƶ��ļ���β
	unsigned filesize = streamReader.tellg();			//��ȡ�α굱ǰλ�� - �ļ���ʼλ�ã��˴�Ϊ�ļ���С
	char* _data = new char[filesize];					//�����ڴ�
	streamReader.seekg(0, std::ios::beg);		//��ת�ؿ�ʼ
	streamReader.read(_data, filesize);		//��ȡ�ļ�
	streamReader.close();
	string data(_data);
	delete[] _data;
	return std::move(data);
}

std::string& file_manager::replaceAll(std::string& context, const std::string& from, const std::string& to)
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
