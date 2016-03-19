#include <cmath>
#include <future>
#include <iomanip>
#include <ios>
#include <iostream>
#include <thread>

int tFuncResult = 0;

int AccumulateExp2(int iterations)
{
	auto acc = 0;
	for(int i = 0; i < iterations; ++i)
	{
		acc += static_cast<int>(exp2(i));
	}
	
	return acc;
}

void ThreadedFunc(int iterations) noexcept
{
	tFuncResult = AccumulateExp2(iterations);
}

int FutureFunc(int iterations) noexcept
{
	return AccumulateExp2(iterations);
}

using namespace std;
int main()
{
	auto tFunc = thread(ThreadedFunc, 5);
	auto fFunc = async(FutureFunc, 6);
	
	tFunc.join();
	cout << tFuncResult << endl;
	cout << fFunc.get() << endl;
}