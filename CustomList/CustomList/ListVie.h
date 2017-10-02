#pragma once
#include <iostream>

namespace ListClass{

class ListVie{	
	
private:

	struct Exemple {
		int value;
		Exemple(){value = 0;}
};
	struct List {
  
	Exemple exemple;
	List* next;
};

	class AddError{
		public:

		std::string errorMassage;
		AddError(){}
		AddError(std::string massage){
				errorMassage = massage; 
		}
	};

	List* begin;	

public:
	
	ListVie(void);
	~ListVie(void);
	void Show();
	void Init(const int*,int);
	void AddBegin(const int);
	void AddEnd(const int);
	void Add(const int);
	void Delete(const int);
		
};

};