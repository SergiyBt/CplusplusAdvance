#include "myArray.h"

myArray::myArray(void){

	a = nullptr;
	nElem = 0;
}

myArray::myArray(int max){
	
	a = new long[max];
	nElem = 0;
}

myArray::~myArray(void){

	delete [] a;
}

int myArray::Elem(){
	
	return nElem;
}

bool myArray::find_slow(long key){  // LINER SEARCH !!!!!!!!!!!!!!!!!!!!!
		
	int j;
	for(j=0; j<nElem; j++)
		if(a[j] == key)
			break;
	if(j == nElem)
		return false;
	else
		return true;
}

int myArray::find_fast(long key){ // SEARCH BINARY !!!!!!!!!!!!!!!!!!!!!!!!
		int lowBound = 0;
		int upperBound = nElem - 1;
		int crnt;

		while(true){
			crnt = (lowBound + upperBound)/2;
			if(a[crnt] == key)
				return crnt;
			else if(lowBound > upperBound)
			 throw Exeption(" Element is not found ! ",0);
			else{
				if(a[crnt] < key)
					lowBound = crnt + 1;
				else
					upperBound = crnt - 1;			
			}		
		}
	}

bool myArray::insert(long value){
		a[nElem] = value;
		nElem++;	
		return true;
	}
	
bool myArray::delet(long value){
		int j;
		for(j=0; j<nElem; j++)
			if(value == a[j])
				break;
		if(j == nElem)
			return false;
		else{
			for(int k=j; k<nElem; k++)
				a[k] = a[k+1];
			nElem--;		
		}	
	}

int myArray::operator[](int i){
		if(i < 0 || i >= nElem)
			throw Exeption(" Entrance for array range ! ",i);
		return a[i];
	}

void myArray::show(){
		for(int j=0; j<nElem; j++)
		std::cout<<" [ "<<j<<" ] = "<<a[j]<<"\n";
	}
	/* ostream&  myArray::operator<<(ostream& os,Array& a){
		for(int j=0; j<a.nElem; j++)
		os<<" [ "<<j<<" ] = "<<a[j]<<endl;
		return os;
	} */

myArray::Exeption::Exeption( std::string n,int v):name(n),value(v)
{}

