#include <iostream>
#include <string>
#include <boost\variant.hpp>
#include <vector>
#include <conio.h>

using namespace std;

class DoubleWrapVisitor : public boost::static_visitor<> {
public:
	void operator()(int& i) const {
	// just samething do
		i += i;
	}
	void operator()(string& s) const{
	// just samething do	
		s += s;
	}
};

int main(){

	union  { int i; float f; } u;
	u.i = 34;
	cout << u.i <<"\n" << u.f <<"\n";
	u.f = 45.6; // ovverride
	cout << u.f <<"\n" << u.i <<"\n";

	boost::variant<int,string> u1,u2;
	u1 = 34;
	u2 = "ssgfgdvfd";
	cout<< u1 << "  " << u2 << "\n";
	u2 = 89;

	int s = boost::get<int>(u1)*boost::get<int>(u2) + 2;
	cout<< s << "\n";

	try {
	string str = boost::get<string>(u2);
	}

	catch(boost::bad_get &get){
		cout<<get.what()<<" \n ";
	}

	boost::variant<int,string> u3;
	cout<< u3 << "\n";

	u3 = 67;
	DoubleWrapVisitor dv;
	boost::apply_visitor(dv,u3);
	cout<< u3 << "\n";
	u3 = "bad";
	boost::apply_visitor(dv,u3);
	cout<< u3 << "\n";

	vector< boost::variant<int,string> > vec;
	vec.push_back("sfdfds");
	vec.push_back(34);

	for(auto i : vec){
		boost::apply_visitor(dv,i);
	}

_getch();
return 0;
}