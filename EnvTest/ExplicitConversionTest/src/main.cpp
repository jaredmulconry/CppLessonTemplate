
struct A
{
	int x;
	explicit operator int(){return x;}
};

void foo(A){}
void foo(int){}

void bar(int){}

int main()
{
	A a;
	a.x = 42;
	foo(a);
	bar(static_cast<int>(a));
}