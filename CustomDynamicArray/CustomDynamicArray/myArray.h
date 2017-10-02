#pragma once
#include <string>
#include <iostream>

class myArray
{

	long* a;	
	int nElem; // Quantity of elemens	

public:
	 
	myArray();
	myArray(int);
	~myArray();
	
	int Elem();
	bool find_slow(long);
	int find_fast(long);
	bool insert(long);
	bool delet(long);
	int operator[](int);
	void show();
	// ostream& operator<<(ostream&,Array&)

	class Exeption{
	public:
		std::string name;
		int value;
		Exeption(std::string ,int );
	};
	
};

