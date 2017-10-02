#include <iostream>
#include <string>
#include <boost\any.hpp>
#include <vector>
#include <conio.h>

using namespace std;

struct Data{
	string name;
	boost::any value;
};

int main(){

	boost::any a,b,c,d;
	a = string("hellow");
	b = 34.5f;
	c = 'f';
	d = vector<int>();

	cout<<boost::any_cast<string>(a)<<"\n"<<
		  boost::any_cast<float>(b)<<"\n"<<
		  boost::any_cast<char>(c)<<"\n";

	if(c.type() == typeid(char))
		cout<<" variable c containes char value "<<endl;
		  
	boost::any_cast< vector<int> >(d).push_back(23);

	int i;
	boost::any p = &i; 
	int* ptr = boost::any_cast<int*>(p);

	vector<boost::any> vec;
	vec.push_back(56);
	vec.push_back('r');
	vec.push_back(p);
	vec.push_back(boost::any());

	vector<Data> vec2; 

_getch();
return 0;
}