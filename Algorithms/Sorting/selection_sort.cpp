#include <iostream>

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int arr[] = {21, 29, 20, 7, 8, 25, 29, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Original array: ";
    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    selectionSort(arr, n);
    std::cout << "\nSorted array: ";
    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}