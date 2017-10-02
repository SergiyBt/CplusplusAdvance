#include <iostream>
#include <boost/optional.hpp>
#include <deque>
#include <conio.h>

using namespace std;

boost::optional<char> print_char_qeue(deque<char> &a){
	if(!a.empty()){
		return boost::optional<char>(a.back());		
	} else
		return boost::optional<char>();
}

struct A {
	int value; 
	string name;
};

int main(){

	deque<char> queue;
	
	//for(int i=0; i<10; i++){
	//	queue.push_back('A' + i);
	//}
	
	//char a;
	
	//for(int i=0; i<10; i++){
	//  a = queue.back(); 
	//	queue.pop_back();
	//	cout<<a<<"\n";
	//}


	boost::optional<char> op;	
	op = print_char_qeue(queue);
		if(!op)
			cout<<" Data is not avalible ! \n";
		else cout<<op.get()<<"\n";	

		op.reset();
		cout<<op.get_value_or('A')<<"\n";
		//op.reset();

		//char* a = op.get_ptr();

		
		A stA;
		//boost::optional<A> op;	
		//boost::optional<A> op(stA);

		boost::optional<A*> op2(&stA);
		(*op2)->name = "sdfdfs";
		(*op2)->value = 12;

		cout<<stA.name<<" "<<stA.value<<" "<<"\n";

		boost::optional<A&> op3(stA);
		op3->name = "ggggg";
		op3->value = 45;

		cout<<stA.name<<" "<<stA.value<<" "<<"\n";

_getch();
return 0;
}
