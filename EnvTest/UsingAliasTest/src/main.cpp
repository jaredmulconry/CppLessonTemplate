#include <algorithm>
#include <ios>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

using str_vector = vector<string>;
template<typename T>
using vec_iterator = typename vector<T>::iterator;

int main()
{
	str_vector v;
	v.push_back("Blah blah");
	v.push_back("Blah bleh");
	v.push_back("Blah bloh");
	v.push_back("Bloh blah");
	v.push_back("Blah bluh");

	for (vec_iterator<string> begin = v.begin(); begin != v.end(); ++begin)
	{
		cout << *begin << ' ';
	}
}