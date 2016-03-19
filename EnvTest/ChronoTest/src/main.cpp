#include <chrono>
#include <ios>
#include <iostream>

using namespace std;
int main()
{
	auto start = chrono::high_resolution_clock::now();
	auto end = chrono::high_resolution_clock::now();
	
	auto elapsed = end - start;
	auto elapsedTime = elapsed.count();
	
	cout << elapsedTime << endl;
	cout << chrono::duration_cast<chrono::duration<double, milli>>(elapsed).count() << endl;
}