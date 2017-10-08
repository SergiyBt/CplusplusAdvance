#pragma once
#include <fstream>
#include <string>
#include <vector>

namespace Program{

class ReadFileBuffer
{
private:

	std::ifstream infile;
	std::string filename;
	std::string str;
	std::string buffer;
	std::vector<std::string> arr;

	class Errors{
	private:
		std::string massage;
	public:
		Errors();
		~Errors();
		Errors(std::string );	
		std::string what();
	};

public:

	ReadFileBuffer(void);
	ReadFileBuffer(std::string);
	~ReadFileBuffer(void);
	std::string getBuffer();
	std::vector<std::string>& Hendle();

};

}