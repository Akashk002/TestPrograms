#include <iostream>
using namespace std;

void countSort(int arr[], int n, int exponent)
{
	int output[n];
	int count[10] = { 0 };

	for (int i = 0; i < n; i++) {
		count[(arr[i] / exponent) % 10]++;
	}

	for (int i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}

	for (int i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exponent) % 10] - 1] = arr[i];
		count[(arr[i] / exponent) % 10]--;
	}

	for (int i = 0; i < n; i++) {
		arr[i] = output[i];
	}
}

void radixSort(int arr[], int n) {
	int maxElement = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > maxElement) {
			maxElement = arr[i];
		}
	}

	for (int exponent = 1; maxElement / exponent > 0; exponent *= 10) {
		countSort(arr, n, exponent);
	}
}

void processRadixSort(int arr[], int n) {
	radixSort(arr, n);
}

void displayArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void fillDynamicArrayWithRandomValues(int** arr, int* n) {
	cout << "Enter the size of the array: ";
	cin >> *n;
	*arr = new int[*n];
	srand(time(0));
	for (int i = 0; i < *n; i++) {
		(*arr)[i] = rand() % 1000;
	}
}

int main() {
	int* arr;
	int n;
	fillDynamicArrayWithRandomValues(&arr, &n);
	cout << "Unsorted array: ";
	displayArray(arr, n);
	processRadixSort(arr, n);
	cout << "Sorted array: ";
	displayArray(arr, n);
	delete[] arr;
	return 0;
}
