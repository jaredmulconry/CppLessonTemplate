
class A
{
	int x;
public:
	A() : x(){}
	explicit A(int x1) : A() {x = x1;}
};

int main()
{
	A a;
	int x = 42;
	A b(x);
}