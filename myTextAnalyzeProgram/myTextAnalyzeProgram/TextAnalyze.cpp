#include "TextAnalyze.h"
#include "ReadFileBuffer.h"

namespace Program{

TextAnalyze::TextAnalyze(void)
{
}

TextAnalyze::TextAnalyze(std::string filename)
{
	
	p = new ReadFileBuffer(filename);
	
	str1 = p->getBuffer();
	vec1 = p->Hendle();	
	 
}

TextAnalyze::~TextAnalyze(void)
{
	delete p;
}

void TextAnalyze::Analyze(){
	
	for(int i=0; i<vec1.size(); i++){
		word = vec1[i];
		key = 1;		
		n = multmap.count(word);
		while(n){			
			++key;
			n--;			
		}		
		multmap.insert(make_pair(word,key));		
	}
}

void TextAnalyze::count(){
	std::cout<<"\n Words is "<<multmap.size()<<".";
}

void TextAnalyze::read(){
    std::cout<<"\n FileData: \n"<<str1<<"\n";
}

void TextAnalyze::show_R_W(){
	std::cout<<"\n Repeatable words: \n\n";

	iter4 = multmap.begin();	
	for(iter3 = multmap.begin(); iter3 != multmap.end(); iter3++){
		if((*iter4).second < (*iter3).second)
			std::cout<<iter3->first << " -- " << iter3->second << "\n";
	}
	std::cout<<"\n";
}

void TextAnalyze::show_Not_R_W(){
	std::cout<<" Words are not repeatable: \n\n";
	
	for( iter3 = multmap.begin(); iter3 != multmap.end(); iter3 = multmap.upper_bound(iter3->first))
  {
      std::cout << iter3->first << " -- " << iter3->second << "\n";
  }
	std::cout<<"\n ";
 }

}