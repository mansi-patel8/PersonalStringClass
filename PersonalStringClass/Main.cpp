/*
* Name: Mansi Patel
* Purpose: The purpose of this program is to create a simple str class that mimic the functionality of the std::string class. 
			Here we are mainly implementing assignment operator(=) and concatenation operator(+) for string
*/

#include "String.h"

int main()
{
	str s1;
	cout << s1 << endl;

	str s2("Hello");
	cout << s2 << endl;

	str s3("World");
	//cout << s3 << endl;

	str s4 = s2 + " " + s3;
	cout << s4 << endl;

	str s5, s6;
	cin >> s5 >> s6;
	cout << s5 << ' ' << s6;

	return 0;
}