#include <iostream> 
#include <ctime>
#include <time.h>
#include <algorithm>
#include <math.h>
using namespace std;


void hanoi_1(int n, char start, char finish, char temp)
{

	if (n == 0)
	{
		return;
	}
	else
	{
		hanoi_1(n - 1, start, temp, finish);
		cout << "move disk from tower " << start << " to tower " << finish << endl << endl << endl;
		hanoi_1(n - 1, temp, finish, start);
	}
}



void hanoi_2(int n, int a, int b)
{
	if (n == 1)
		cout << "move disk " << a << " to disk " << b << endl;
	else
	{
		int tmp = 6 - a - b;
		hanoi_2(n - 1, a, tmp);
		cout << "move disk " << a << " to disk " << b << endl;
		hanoi_2(n - 1, tmp, b);
	}
}

int main()
{
	int n1 = 5, n2 = 5;
	cout << " N1 = " << n1 << endl;
	cout << " N2 = " << n2 << endl;
	
	

	unsigned int start1 = clock();
	hanoi_1(n1, 'A', 'B', 'T');
	unsigned finish1 = clock();

	unsigned int start2 = clock();
	hanoi_2(n2, 1, 2);
	unsigned finish2 = clock();
	
	cout << "\nOperations 1 = " << pow(2, n1) - 1 << endl;
	cout << "\nOperations 2 = " << pow(2, n2) - 1 << endl;
	
	cout << "\nTime 1 = " << finish1 - start1 << endl;
	cout << "\nTime 2 = " << finish2 - start2 << endl;
	system("pause");
	return 0;
}
