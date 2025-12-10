#include <iostream>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low-1;
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[high]);
    return i+1;
}

void quicksort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {21, 29, 20, 7, 8, 25, 29, 13};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::cout << "Original array: ";
    for(int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    quicksort(arr, 0, n - 1);
    std::cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    return 0;
}