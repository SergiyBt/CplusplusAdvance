#include <iostream>
#include <string>
#include <conio.h>
#include <boost\lexical_cast.hpp>
#include <array>

using namespace std;
using boost::lexical_cast;
using boost::bad_lexical_cast;

int main(){

  int a = 39;
  string str = lexical_cast<string>(a) + lexical_cast<string>('s') + lexical_cast<string>("34.5");
  cout<<str<<"\n";
  array<char,10> arr;
  string b = "3242sdfs";

	arr = lexical_cast< array<char,10> >(b);

	for(auto i : arr){
	cout<<i<<"\n";
	}

	try{
	   a = lexical_cast<int>("345rt");
	}catch(bad_lexical_cast &exp){
		cout<<exp.what()<<"\n";
	}

	a = lexical_cast<int>("43654mmm",5);

	cout<<a<<"\n";
	
_getch();
return 0;
}