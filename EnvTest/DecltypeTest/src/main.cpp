#include <ios>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a = "Hello World!";
	cout << a << endl;
	decltype(a) b = a;
	cout << b << endl;
	decltype(a + b) c = a + b;
	cout << c << endl;
}