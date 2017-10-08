#pragma once
#include "ReadFileBuffer.h"
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <iostream>

namespace Program{

class TextAnalyze
{
private:

	ReadFileBuffer* p;
	std::string filename;
	std::string str1;
	std::vector<std::string> vec1;

	std::multimap<std::string,int> multmap;	
	std::multimap<std::string,int>::const_iterator iter3;
	std::multimap<std::string,int>::const_iterator iter4;

	int key;
	int temp1,temp2;
	std::string word;
	int n;

public:
	TextAnalyze(void);
	TextAnalyze(std::string);
	~TextAnalyze(void);
	void Analyze();
	void count();
	void show_R_W();
	void show_Not_R_W();
	void read();
};

}