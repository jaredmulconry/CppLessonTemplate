#include <utility>

struct A
{
	int x;
	
	A() = default;
	explicit A(int x) : x(x){}
	A(const A&) = delete;
	A(A&&) = default;
	A& operator=(A&&) = default;
};

void foo(int){}
void foo(short) = delete;

void bar(A){}

int main()
{
	A a;
	int x = 42;
	A a1(x);
	
	foo(a1.x);
	bar(std::move(a1));
}