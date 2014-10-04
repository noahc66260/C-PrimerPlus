// usetime4.cpp -- using the fourth draft of the Time class
// compile pe11-4.cpp and mytime4.cpp together
// This is listing 11.12 in Stephen Prata's C++ Primer Plus
#include<iostream>
#include "mytime4.h" 

int main()
{
	using std::cout;
	using std::endl;
	Time aida(3,35);
	Time tosca(2, 48);
	Time temp;

	cout << "Aida and Tosca:\n";
	cout << aida << "; " << tosca << endl;
	temp = aida + tosca;
	cout << "Aida + Tosca: " << temp << endl;
	temp = aida * 1.17;
	cout << "Aida * 1.17: " << temp << endl;
	cout << "10 * Tosca: " << 10 * tosca << endl;

	return 0;
}
