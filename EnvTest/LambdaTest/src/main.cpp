#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int main()
{
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

	typedef vector<string>::iterator iterator;

	iterator begin = v.begin();
	iterator end = v.end();

	std::copy(begin, end, ostream_iterator<string>(cout));
	sort(begin, end, [](const string& x, const string& y) { return x.length() < y.length(); });
	std::copy(begin, end, ostream_iterator<string>(cout));

	string toFind = "eighth";
	iterator lb = find_if(begin, end, [&toFind](const string& str) { return str == toFind; });
	if (lb != end)
	{
		cout << "found " << *lb << endl;
	}
}