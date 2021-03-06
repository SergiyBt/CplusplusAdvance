#include "ListVie.h"

namespace ListClass{

ListVie::ListVie(void)
{
	begin = NULL;
	Exemple::Exemple();
}

ListVie::~ListVie(void)
{
	if(begin == NULL)
		return;

	List* temp = begin;
	List* t;

	while (temp)
	{
		t = temp;
		temp = temp->next;
		delete t;
	}

	begin = 0;
}

void ListVie::Show(){

	List* temp = begin;
	while (temp)
	{
		std::cout<<temp->exemple.value<<" -> ";
		temp = temp->next;
	}
	std::cout<<"NULL"<<std::endl;
}

void ListVie::Init(const int* A,int size){

	int i = 0;
	begin = new List;
	begin->exemple.value = A[i];
	begin->next = 0;

	List* end = begin;

	for(i=1; i<size; i++){
		end->next = new List;
		end = end->next;
		end->exemple.value = A[i];
		end->next = 0;		
	}
}

void ListVie::AddBegin(const int A){

	List* temp = new List;
	temp->exemple.value = A;

	if(!(begin)){
		temp->next = 0;
		begin = temp;
		return;
	}

	if(A > begin->exemple.value){
		throw AddError(" Added value is not allowed int function AddBegin(). ");
		return;
	}

	temp->next = begin;
	begin = temp;
}

void ListVie::AddEnd(const int A){

	List* temp = new List;
	temp->exemple.value = A;
	temp->next = 0;

	if(!(begin)){
		temp->next = 0;
		begin = temp;
		return;
	}

	List* end = begin;

	while(1){

		if(end->exemple.value > A){
			throw AddError(" Added value is not allowed in function AddEnd(). ");
			return;
		}
			
		
		if(end->next == 0){
			end->next = temp;
			return;
		}
		end = end->next;
	}
}

void ListVie::Add(const int A){

	List* temp = new List;
	temp->exemple.value = A;

	if(!(begin)){
		temp->next = 0;
		begin = temp;
		return;
	}

	List* first = begin;

	if(first->exemple.value > A){
	
		temp->next = begin;
		begin = temp;
		return;
	}

	List* second = first->next;

	while(second){
	
		if(second->exemple.value > A && first->exemple.value < A){
		
			first->next = temp;
			temp->next = second->next;
			begin = first;
			return;
		}
		first = second;
		second = second->next;	
	}

	first->next = temp;
	temp->next = 0;	
}

void ListVie::Delete(const int A){

	if(!(begin))
		return;

	List* temp = begin;
	

	if(temp->exemple.value == A){
		
		begin = temp->next;
		delete temp;
		return;
	}

	List* second = temp->next;

	while(second){
	
		if(second->exemple.value == A){
		
			temp->next = second->next;
			delete second;
			return;
		}
		temp = second;
		second = second->next;	
	}
}

};