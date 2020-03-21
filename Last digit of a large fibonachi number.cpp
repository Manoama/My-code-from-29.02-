#include<iostream>
#include <ctime>
#include <time.h>
using namespace std;


//************----Find last digit of a large fibonachi number----********
int Last_digit(int n)
{
	int* arr_last_digits = new int[n];
	arr_last_digits[0] = 0;
	arr_last_digits[1] = 1;
	for (int i = 2; i < n; i++)
	{
		if ((arr_last_digits[i - 1] + arr_last_digits[i - 2]) >= 10)
		{
			arr_last_digits[i] = (arr_last_digits[i - 1] + arr_last_digits[i - 2]) % 10;
		}
		else
		{
			arr_last_digits[i] = arr_last_digits[i - 1] + arr_last_digits[i - 2];
		}
		
	}
	int last_digit_n = arr_last_digits[n - 1];
	delete[] arr_last_digits;
	return last_digit_n;
}



int main()
{
	cout << Last_digit(9) << endl;
	
	system("pause");
	return 0;
}