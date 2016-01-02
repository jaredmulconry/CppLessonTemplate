#include <ios>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int a[] = {1, 2, 5, 8, 11, 14, 28, 5, 7, 111, 3, 12};

	for (const int& x : a)
	{
		cout << x << endl;
	}

	vector<string> v;
	v.emplace_back("first");
	v.emplace_back("second");
	v.emplace_back("third");
	v.emplace_back("fourth");
	v.emplace_back("fifth");
	v.emplace_back("sixth");
	v.emplace_back("seventh");
	v.emplace_back("eighth");
	v.emplace_back("nineth");
	v.emplace_back("tenth");

	for (const string& s : v)
	{
		cout << s << endl;
	}
}