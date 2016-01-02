#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using namespace std;

auto ProduceString(int charCount) -> string
{
	auto res = string();
	res.reserve(charCount);

	while (charCount > 0)
	{
		res += std::to_string(charCount);
	}

	return res;
}

int main()
{
	auto a = 42;
	const auto& b = a;
	++a;
	cout << boolalpha << (a == b) << endl;

	auto str = ProduceString(10);
	cout << str << endl;
}