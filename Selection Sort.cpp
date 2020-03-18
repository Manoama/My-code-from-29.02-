#include <iostream>
#include <ctime>
using namespace std;

int comp = 0;
int cop = 0;
int main()
{
	unsigned int start = clock();

	srand(time(NULL));
	int size = 100;
	int*arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
	cout << "Unsorted array :" << endl << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
	}
	
	for (int i = 0; i < size-1; i++)
	{
		int min = i;
		for (int j = i; j < size; j++)
		{
			++comp;
			if (arr[j] < arr[min])
			{
				++cop;
				min = j;
			}
		}
		++comp;
		if (i != min)
		{
			++cop;
			int tmp;
			tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;

		}
	}

	cout << "Sorted array :" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
	}
	
	delete[] arr;
	unsigned int end = clock();
	unsigned int time = end - start;
	cout << endl << "Time = " << time;
	system("pause");
	return 0;

}




































//#include<iostream>
//#include<ctime>
//#include<time.h>
//using namespace std;
//
//int cpng = 0;
//int cmprsn = 0;
//int main()
//{
//	srand(time(NULL));
//	setlocale(LC_ALL, "rus");
//	int size = 10000;
//	int * arr = new int[size];
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = rand() % 10000;
//	}
//	cout << endl;
//	for (int i = 0; i < size; i++)
//	{
//		cout << i << "-ый элемент :\t" << arr[i] << endl;
//	}
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = i; j < size; j++)
//		{
//			++cmprsn;
//			if (arr[i] > arr[j])
//			{
//				++cpng;
//				int tmp=arr[i];
//				arr[i] = arr[j];
//				arr[j] = tmp;
//			}
//		}
//	}
//	cout << "\tОтсортированный массив: \n";
//	for (int i = 0; i < size; i++)
//	{
//		cout << i << "-ый элемент :\t" << arr[i] << endl;
//	}
//	delete[] arr;
//	cout << "Number of copying = " << cpng << endl;
//	cout << "Number of comparison = " << cmprsn << endl;
//	system("pause");
//	return 0;
//}