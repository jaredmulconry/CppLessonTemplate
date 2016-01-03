
struct A
{
	A(){}
	virtual ~A(){}
	
	virtual void foo(int) = 0;
};

struct B : public A
{
	int x;
	B(){}
	virtual ~B(){}
	
	void foo(int) override {}
};

struct C : public A
{
	int x;
	C(){}
	virtual ~C(){}
	
	void foo(int) override final {}
};

struct D final  : public A
{
	int x;
	D(){}
	virtual ~D(){}
	
	void foo(int) override {}
};

int main()
{
	B b;
	C c;
	D d;
	
	A& rb = b;
	A& rc = c;
	A& rd = d;
	rb.foo(11);
	rc.foo(22);
	rd.foo(33);
}