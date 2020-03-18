#pragma once
#include <iostream>
#include<ctime>
using namespace std;

int comp = 0;
int cop = 0;
void quickSort(int arr[], int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	/* partition */
	while (i <= j) {
		++comp;
		while (arr[i] < pivot)
			i++;
		++comp;
		while (arr[j] > pivot)
			j--;
		++comp;
		if (i <= j) {
			++cop;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};

	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);

}