
enum class A;
enum class B : unsigned short;

enum class A{a, b, c};
enum class B :  unsigned short{a, b, c};

void foo(A){}
void foo(B){}

int main()
{
	A a1 = A::a;
	B b1 = B::c;
	foo(a1);
	foo(b1);
}
