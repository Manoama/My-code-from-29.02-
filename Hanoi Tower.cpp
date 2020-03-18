#include <iostream> 
#include <ctime>
#include <time.h>
#include <algorithm>
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
	hanoi_1(6, 'A', 'B', 'T');
	hanoi_2(7, 1, 2);
	system("pause");
	return 0;
}
