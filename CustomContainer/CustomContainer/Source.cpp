#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class Person // SAMPLE OF DATA CLASS
{
private:
	string name;
	string suname;
	int age;
public:
	Person():name(" "),suname(" "),age(0){}
	Person(string n,string s,int a):name(n),suname(s),age(a){}
	void show(){
		cout<<" Name "<<name<<endl
			<<" Suname "<<suname<<endl
			<<" Age "<<age<<endl;
	}
	string getName(){
		return name;
	}
	friend ostream& operator<<(ostream& os,Person p){
		os <<" Name "<<p.name<<endl
			<<" Suname "<<p.suname<<endl
			<<" Age "<<p.age<<endl;
		return os;
	}
};

class Array 
{
private:
	Person* a;	
	int nElem; // Quantity of elemens
	int MAX;

	bool sortString(const string& str1,const string& str2) const {
	return (str1.compare(str2) < 0 ? false : true); 
	}

public:
	class Exeption{
	public:
		string name;
		int value;
		Exeption(string n,int v):name(n),value(v)
		{}
	}; 
	Array(){
		a = nullptr;
		nElem = 0;
		MAX = 0;
	}
	Array(int max){
		this->MAX = max;
		a = new Person[MAX];
		nElem = 0;
	}
	~Array(){
		delete [] a;
	}
	int Elem(){
		return nElem;
	}
	bool find_slow(string searchname){  // LINEAR SEARCH
		int j;
		for(j=0; j<nElem; j++)
			if(a[j].getName().compare(searchname) == 0)
				break;
		if(j == nElem)
			return false;
		else
			return true;
	}
	int find_fast(string searchname){   // ORDER ARRAY ! BINARY SEARCH !
		int lowBound = 0;
		int upperBound = nElem - 1;
		int crnt;

		while(true){
			crnt = (lowBound + upperBound)/2;
			if(a[crnt].getName() == searchname)
				return crnt;
			else if(lowBound > upperBound)
			 throw Exeption(" Element is not found ! ",0);
			else{
				if(a[crnt].getName() < searchname)
					lowBound = crnt + 1;
				else
					upperBound = crnt - 1;			
			}		
		}
	}
	bool insert(string name,string suname,int age){
		if(MAX == nElem)
			return false;
		a[nElem] = Person(name,suname,age);
		nElem++;	
		return true;
	}
	
	bool insert(Person* prs){
		if(MAX == nElem)
			return false;
		a[nElem] = *prs;
		nElem++;	
		return true;
	}
	
	bool delet(string name){
		int j;
		for(j=0; j<nElem; j++)
			if(name == a[j].getName())
				break;
		if(j == nElem)
			return false;
		else{
			for(int k=j; k<nElem; k++)
				a[k] = a[k+1];
			nElem--;		
		}	
	}
	Person operator[](int i){
		if(i < 0 || i >= nElem)
			throw Exeption(" Entrance for array range ! ",i);
		return a[i];
	}
	void show(){
		for(int j=0; j<nElem; j++){
			a[j].show();
			cout<<endl;
		}
	} 
	void sort(){ // LINEAR SORT SLOW
		for(int i=0; i<nElem; i++)
			for(int j=i+1; j<nElem; j++)
		{
			if(sortString(a[i].getName(),a[j].getName())){
				Person temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	/* ostream& operator<<(ostream& os,Array& a){
		for(int j=0; j<a.nElem; j++)
		os<<" [ "<<j<<" ] = "<<a[j]<<endl;
		return os;
	} */
};


int main(){
	
	//Person a("Aaaa","afdsfs",34),b("Fklnkn","afasfdsf",34),c("Dsdfdsf","afsdfsf",33),d("Bdsf","asdfs",21);
	
	Array arr(10);
	Person* a = new Person("DDDD","sdds",45);
	Person* b = new Person("AAAAaa","sdds",45); 
	Person* d = new Person("Bsdfhs","sdds",45); 

	arr.insert("Aaaa","afdsfs",34);
	arr.insert("Fklnkn","afasfdsf",34);
	arr.insert("Dsdfdsf","afsdfsf",33);
	arr.insert("Bdsf","asdfs",21);

	arr.insert("Aaaa","afdsfs",34);
	arr.insert("Fklnkn","afasfdsf",34);
	arr.insert("Dsdfdsf","afsdfsf",33);
	arr.insert("Bdsf","asdfs",21);
	
	arr.insert(a);
	arr.insert(b);
	arr.insert(d);

	arr.sort();

	arr.show();

	//arr.delet("Aaaa");
		
	if(arr.find_slow("Bdsf"))
		cout<<" Find ! \n";
	else cout<<" Not find ! \n";

	//arr.show();	

	
_getch();
return 0;
}