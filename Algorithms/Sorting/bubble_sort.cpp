#import <iostream>

void bubbleSort(int arr[], int n){
    bool swapped;

    for(int i = 0; i < n-1; i++){
        swapped = false;

        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                std::swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        if(!swapped)
            break;
    }
}

int main(){
    int arr[] = {29, 20, 21, 13, 7 ,8, 25, 29};
    int n = sizeof(arr)/sizeof(arr[0]);

    std::cout << "Unsorted array: \n";
    for(int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    bubbleSort(arr, n);
    std::cout << "Sorted array: \n";
    for(int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
}