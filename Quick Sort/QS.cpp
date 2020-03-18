#include <iostream>
#include <ctime>
#include "qs.h"
using namespace std;


void print(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "-";
	}
	cout << endl;
}

int main()
{
	unsigned int start = clock();
	srand(time(NULL));
	int n = 10000;

	cout << "Array Size: \t" << n << endl;
	cout << endl;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) 
		arr[i] = rand() % 100;

	print(arr, n);
	quickSort(arr, 0, n - 1);
	print(arr, n);
	
	cout << comp << endl;
	cout << cop << endl;

	unsigned int end = clock();
	unsigned int time = end - start;
	cout << endl << "Time = " << time << endl;
	system("pause");
	return 0;

}