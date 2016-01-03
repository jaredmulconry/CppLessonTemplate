
constexpr int foo()
{
	return 2 + 4;
}

int main()
{
	constexpr int a = 42;
	constexpr int b = foo();
	int c = foo();
	(void)a;
	(void)b;
	(void)c;
}
