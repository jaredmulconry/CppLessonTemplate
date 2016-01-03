#include <ios>
#include <iostream>
#include <string>

using namespace std;

auto ProduceString(int charCount) -> string
{
	string res;
	res.reserve(charCount);

	while (charCount > 0)
	{
		res += std::to_string(charCount);
		--charCount;
	}

	return res;
}

int main()
{
	string str = ProduceString(10);
	cout << str << endl;
}