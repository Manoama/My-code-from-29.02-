#include<iostream>
#include <ctime>
#include <time.h>
using namespace std;


// Fib
int Fib(int n)
{
	
	int previous = 0;
	int current = 1;
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	for (int i = 0; i < n; i++)
	{
		int new_current = current + previous;
		previous = current;
		current = new_current;
	}
	return current;
}


int main()
{
	for (int i = 0; i < 10; i++)
	{
		cout << Fib(i) << endl;
	}
	system("pause");
	return 0;
}