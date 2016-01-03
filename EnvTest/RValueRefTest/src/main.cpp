#include <utility>

template<typename T>
void bar(T&&){}

void foo(const int&)
{
	
}
void foo(int&&)
{
	
}

int main()
{
	int a = 42;
	foo(a);
	foo(std::move(a));
	int b = 24;
	bar(b);
	bar(std::move(b));
}