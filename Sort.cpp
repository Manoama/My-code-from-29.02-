//#include<iostream>
//using namespace std;
//
//int main()
//{
//	setlocale(LC_ALL, "rus");
//	int size = 0;
//	cin >> size;
//	int * arr = new int[size];
//	for (int i = 0; i < size; i++)
//	{
//		cin >> arr[i];
//	}
//	cout << endl;
//	for (int i = 0; i < size; i++)
//	{
//		cout << i << "-ый элемент :\t" << arr[i] << endl;
//	}
//	for (int i = 0; i < size; i++)
//	{
//		//int tmp = arr[i];
//		for (int j = i; j < size; j++)
//		{
//			if (arr[i] > arr[j])
//			{
//				int tmp=arr[i];
//				arr[i] = arr[j];
//				arr[j] = tmp;
//				//swap(arr[i],arr[j]);
//
//			}
//		}
//	}
//	cout << "\tОтсортированный массив: \n";
//	for (int i = 0; i < size; i++)
//	{
//		cout << i << "-ый элемент :\t" << arr[i] << endl;
//	}
//
//	system("pause");
//	return 0;
//}