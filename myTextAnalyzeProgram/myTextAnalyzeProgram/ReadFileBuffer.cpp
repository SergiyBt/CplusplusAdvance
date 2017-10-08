#include "ReadFileBuffer.h"
#include "ReadFileBuffer.h"

namespace Program {

ReadFileBuffer::ReadFileBuffer(void)
{
}

ReadFileBuffer::ReadFileBuffer(std::string filename){
	this->filename = filename;
	infile.open(filename);
	if(infile.is_open()){
		while(getline(infile,str)){
			buffer += str; 
		}
	infile.close();
	str.clear();
	}
		else throw Errors(" File is not open. Name is not correct or file is not exist. ");
}

ReadFileBuffer::~ReadFileBuffer(void)
{
}

std::string ReadFileBuffer::getBuffer(){		
		return buffer;

}

std::vector<std::string>& ReadFileBuffer::Hendle(){
		for(int i=0; i<buffer.size(); i++){		
		if(buffer[i] == ' ' || buffer[i] == ',' || buffer[i] == '!' || buffer[i] == '?' || buffer[i] == '(' 
			|| buffer[i] == ')' || buffer[i] == ':' || buffer[i] == ';'){
			if(str !=" " && str != "," && str != "!" && str != "?")
				arr.push_back(str);
			str.clear();				
			}	
		str += buffer[i];
		}
		return arr;
}

ReadFileBuffer::Errors::Errors(){
	
}

ReadFileBuffer::Errors::Errors(std::string massage){
	this->massage = massage;
}
 
std::string ReadFileBuffer::Errors::what(){
	return massage;
}

ReadFileBuffer::Errors::~Errors(){
}

}