#include <iostream>		
#include <fstream>
#include <string>

using namespace std;

// SHOW MENU 
void menu(){ 
	cout<<"******************* EnCrypt Program ******************* \n\n";
	cout<<" 1. EnCrypt and save file. (Enter 1 please) \n";
	cout<<" 2. DeCrypt and save file. (Enter 1 please) \n";
	cout<<" 3. Exit... \n";
}

// FUNCTION THAT ENCRYPT INFORMATION AND SAVE IN THE FALE
void Do1(){
		
		string filename,filenamesave;
		int key;		
		
		cout<<"Enter key value for enCrypt... (May be integer) ";
		cin>>key;
		cout<<"Enter entire filename... "; 
		cin>>filename;
		
		ifstream fin(filename);
		if(!fin.is_open()){
			cout<<" File is not open ! "<<endl;
		} else {
			cout<<" File is open ! "<<endl;
		}
		
		char separator;
		cout<<"Enter char to end ";
		cin>>separator;
		cout<<endl;

		cout<<" Enter entire filename to save ";
		cin>>filenamesave;
		cout<<endl;
		
		cout<<" EnCrypting and save file..."<<endl;

		string str1;			
		getline(fin,str1,separator);		
	
		int length = str1.size();
		char* str3 = new char[length+1];

		for(int i=0; i<length; i++){
			str3[i] = str1[i];
		}
		str3[length+1] = '\0';
	
		for(int i=0; i<length; i++){
			str3[i] = str3[i] ^ key;
		}

		ofstream fout(filenamesave);

		for(int i=0; i<strlen(str3); i++){
			fout<<str3[i];
		}
}

// FUNCTION THAT DECRYPT INFORMATION AND SAVE IN THE FALE
void Do2(){
	
		string filename,filenamesave;
		int key;		
		
		cout<<"Enter key value for deCrypt... (May be integer) ";
		cin>>key;
		cout<<"Enter entire filename... "; 
		cin>>filename;
		
		ifstream fin(filename);
		if(!fin.is_open()){
			cout<<" File is not open ! "<<endl;
		} else {
			cout<<" File is open ! "<<endl;
		}		

		cout<<" Enter entire filename to save ";
		cin>>filenamesave;
		cout<<endl;
		
		cout<<" DeCrypting and save file..."<<endl;

		string str1;	
		while(!fin.eof())
			getline(fin,str1);		
	
		int length = str1.size();
		char* str3 = new char[length+1];

		for(int i=0; i<length; i++){
			str3[i] = str1[i];
		}
		str3[length+1] = '\0';
	
		for(int i=0; i<length; i++){
			str3[i] = str3[i] ^ key;
		}

		ofstream fout(filenamesave);

		for(int i=0; i<strlen(str3); i++){
			fout<<str3[i];
		}	
}

// MAIN FUNCTION
int main()
{	
		
	int choise;	
	menu();	
	
	while((cin>>choise) && (choise == 1 || choise == 2)){
		
		if(choise == 1){
			Do1();			
		}
		
		if(choise == 2 ){
			Do2();
		}		
	}

	cout<<endl<<" Exit...\n ";
	system("pause");
return 0;
}