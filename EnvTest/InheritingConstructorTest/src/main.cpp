
struct A
{
	A(){}
	A(int){}
};

struct B : public A
{
	using A::A;
};

int main()
{
	int x = 42;
	A a;
	A a1(x);
	B b;
	B b1(x);
}