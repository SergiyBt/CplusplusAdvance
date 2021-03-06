#include <iostream>
#include <conio.h>
#include <string>
#include <random>
#include <time.h>

using namespace std;

template<class T>
void Swap(T& a,T& b){ 
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
void arr_sort_bubble(T a,int lenth){
	for(int i=0; i<lenth; i++){
	
		for(int j(lenth-1); j>i; j--)
			if(a[i] > a[j])
				Swap(a[i],a[j]);
	}
}

template<class T>
void arr_sort_select(T a,int lenth){
	int i,j,min;
	for( i=0; i<lenth-1; i++){
	min = i;
	for(j=i+1; j<lenth; j++)
			if(a[j] < a[min])
				min = j;
		Swap(a[i],a[min]);	
	}
}

template<class T>
void arr_sort_insert(T* a,int lenth){
	int i,j;
	for(i=1; i<lenth; i++){
		T temp = a[i];
		j = i;
		while(j>0 && a[j-1] >= temp){
		a[j] = a[j-1];
		--j;		
		}
	a[j] = temp;
	}
}

template<class T1,class T2> // LINEAR SEARCH
auto find(T1 a,T2 elemt,int size) -> decltype(a){
	for(int i=0; i<size; i++){
	
		if(a[i] == elemt )
			return (a+i);
	}
	return NULL;
}


int main(){
	
	srand(time(NULL));

	const int n =1000;
	int a[n];

	for(int i=0; i<n; i++)
		a[i] = rand()%100;

	arr_sort_insert(a,n);
	//arr_sort_bubble(a,n);
	//arr_sort_select(a,n);

	for(int i=0; i<n; i++)
		cout<<a[i]<<"  ";
	
	
_getch();
return 0;
}