#include "ListVie.h"
#include <conio.h> // for getch();

using namespace std;
using namespace ListClass;

int main()
{	
	ListVie list;

	list.Add(300);
	list.AddBegin(10);
	list.AddEnd(345);
	list.Delete(10);

	list.Show();
	
	_getch();
return 0;
}