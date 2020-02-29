#include<iostream>
using namespace std;
int c = 0;



//////////////////////////////////////////////////////////////////////////////////////
//                                  лаба 1
/////////////////////////////////////////////////////////////////////////////////////

// ханойские башни

// сам
void hanoi(int n, char start, char finish, char temp)
{
	
	if (n == 0)
	{
		return;
	}
	else
	{
	//	cout << "start " << start << " finish " << finish << " temp " << temp << endl;
		hanoi(n - 1, start, temp,finish);
		cout << "move disk from tower " << start << " to tower " << finish << endl << endl << endl;
		++c;
		hanoi(n - 1, temp, finish,start);
	}
}


// в интеренете
void hanoi_tower(int n, int a, int b)
{
	if(n == 1)
		cout << "move disk " << a << " to disk " << b << endl;
	else
	{
		int tmp = 6 - a - b;
		hanoi_tower(n - 1, a, tmp);
		cout << "move disk " << a << " to disk " << b << endl;
		hanoi_tower(n - 1, tmp, b);
	}
}




int counter = 0;
int DigitCounter(int n)
{
	if (n / 10 == 0)
	{
		++counter;
		return 1;
	}
	DigitCounter(n / 10);
	++counter;
}



// числа фибоначчи
int fib(int n)
{
	if (n < 0)
	{
		cout << "wrong intut" << endl;
		return 0;
	}
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fib(n - 1) + fib(n - 2);

}


///////////////////////////////////////////////////////////////////////
//						лаба 2
///////////////////////////////////////////////////////////////////////

//сортировка выбором

//void min(int*, int, int);
//void swap(int& a, int& b);
//
//
//void sort(int* arr,int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		min(arr, size, i);
//	}
//	return;
//}





//void min(int * arr, int size, int i)
//{
//	int tmp = arr[i];
//	int id = 0;
//	for (int j = i; j < size; j++)
//	{
//		if (tmp > arr[j])
//		{
//			tmp = arr[j];
//			id = j;
//		}
// 	}
//	swap(arr[i], arr[id]);
//}
//
//void swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
int main()
{
	cout << DigitCounter(331);
	//cout << 3150 % 10;
//	hanoi(6,'A','B','C');

	/*int size = 0;
	cin >> size;
	int * arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	sort(arr, size);
	
	for (int i = 0; i < size; i++)
	{
		cout << arr[i];
	}*/

	
	system("pause");
	return 0;
}















































