#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using namespace std;

template<typename... Ts>
void print_all_args(const Ts&...){}
template<typename T, typename... Ts>
void print_all_args(const T& v, const Ts&... vs)
{
	cout << v << ' ';
	print_all_args(vs...);
}

int main()
{
	string a = "Some words";
	int b = 42;
	string c = "So many words!";
	
	print_all_args(a, b, c);
	cout << endl;
	print_all_args(c, a, b);
}
