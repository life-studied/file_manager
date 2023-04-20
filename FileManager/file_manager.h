#pragma once
#include <string>
#include <vector>
#include <fstream>
using std::string;
using std::vector;
class file_manager
{
public:
	file_manager();
	string getData(string filename) throw(std::ifstream::failure);
	string& replaceAll(
		string& context,
		const string& from,
		const string& to);
	vector<string> parseFileToWords(const string& fileTxt);
};

