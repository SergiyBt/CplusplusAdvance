#include <iostream>
#include <conio.h> // for getch()
#include <string>
#include "myArray.h"

using namespace std;

int main(){
	
	myArray arr(100);

	for(int i=0; i<100; i++)
	arr.insert(i);
	
	arr.show();

	try{

	int index = arr.find_fast(230);
	cout<<" Found element index = "<<index;
		
	}catch(myArray::Exeption ex){
		cout<<" Error massage: "<<ex.name<<endl;
		cout<<" Error value: "<<ex.value;
	}
	arr.delet(34);
	arr.delet(50);

	arr.show();
	
	
_getch();
return 0;
}