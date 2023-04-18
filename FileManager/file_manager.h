#pragma once
#include <string>
using std::string;
using std::wstring;
class file_manager
{
public:
	file_manager();
	string&& getData(string filename);
	std::string& replaceAll(
		std::string& context,
		const std::string& from,
		const std::string& to);
};

