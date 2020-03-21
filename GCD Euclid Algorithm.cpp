#include<iostream>
#include<cstdint>
#include <ctime>
#include <time.h>
using namespace std;


// Euclide Algo
int EuclidGCD(int a, int b)
{
	if (a==0)
	{
		return b;
	}
	if (b == 0)
	{
		return a;
	}
	if (a < b)
	{
		return EuclidGCD(a, b%a);
	}
	if (a > b)
	{
		return EuclidGCD(a%b, b);
	}
}
int EuclideGCD_Advanced(int a, int b)
{
	while (a > 0 && b > 0)
	{
		if (a > b)
		{
			a %= b;
		}
		else
		{
			b %= a;
		}
	}
	return a == 0 ? b : a;   // if a==0 then return b else return a
}

int main()
{
	int a, b;
	cin >> a >> b;
//	cout << EuclidGCD(a, b) << endl;
	cout << EuclideGCD_Advanced(a, b) << endl;
	system("pause");
	return 0;
}