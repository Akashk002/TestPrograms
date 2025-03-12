#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void inPlaceMerge(int arr[], int left, int mid, int right) {
    int start2 = mid + 1;
    if (arr[mid] <= arr[start2]) return;
    while (left <= mid && start2 <= right) {
        if (arr[left] <= arr[start2]) {
            left++;
        }
        else {
            int value = arr[start2], index = start2;
            while (index > left) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[left] = value;
            left++;
            mid++;
            start2++;
        }
    }
}

void inPlaceMergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        inPlaceMergeSort(arr, left, mid);
        inPlaceMergeSort(arr, mid + 1, right);
        inPlaceMerge(arr, left, mid, right);
    }
}

void processInPlaceMergeSort(int arr[], int n) {
    if (n > 1) {
        inPlaceMergeSort(arr, 0, n - 1);
    }
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
    processInPlaceMergeSort(arr, n);
    cout << "Sorted array: ";
    displayArray(arr, n);
    delete[] arr;
    return 0;
}
