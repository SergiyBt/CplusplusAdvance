#include <iostream>		
#include "ReadFileBuffer.h"
#include "TextAnalyze.h"

using namespace std;
using namespace Program;

void menu(){

	cout<<"       Text operation program          \n\n";
	cout<<"1. Analyze and find repeatable words.    \n";
	cout<<"2. Exit... \n";
}

int main()
{	
	menu();
	int choise;
	string filename;

	while((cin>>choise) && choise == 1){

		if(choise == 1){
			
			cout<<" Enter filename "; 
			cin>>filename;
			TextAnalyze t(filename);
			t.Analyze();
			t.read();
			t.count();
			t.show_R_W();
			t.show_Not_R_W();
		}

	system("pause");
	system("cls");
	menu();
	}

	cout<<"\n Exit...\n ";
	system("pause");
return 0;
}