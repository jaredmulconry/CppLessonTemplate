
void foo(int){}
void foo(int*){}

int main()
{
	foo(0);
	foo(nullptr);
}