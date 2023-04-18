#pragma once
#include <string>
#include <fstream>
using std::string;
class file_manager
{
public:
	file_manager();
	string getData(string filename) throw(std::ifstream::failure);
	string& replaceAll(
		string& context,
		const string& from,
		const string& to);
};

