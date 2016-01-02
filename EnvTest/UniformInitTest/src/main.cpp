#include <algorithm>
#include <ios>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int a{ 15 };
	cout << a << endl;

	vector<string> v{"a", "b", "c"};
	v.insert(v.end(), { {"abc"}, {"cdf"}, {"ghi"}});

	copy(v.begin(), v.end(), ostream_iterator<string>(cout));
}