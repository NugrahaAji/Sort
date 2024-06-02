#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {;
    int arr[] = {83, 86, 77, 15, 93, 35, 86, 92, 49, 21};
    int size = sizeof(arr)/sizeof(int);

    auto start = high_resolution_clock::now();
    quicksort(arr, 0, size - 1);
    auto stop = high_resolution_clock::now();
    auto runtime = duration_cast<nanoseconds>(stop - start);

    cout << endl;
    cout << "size: " << size << endl;
    cout << "Runtime: " << runtime.count() << " nanoseconds" << endl;

    cout << "{";
    for(int i = 0; i < size; i++){
        cout << arr[i];
        if(i < size - 1){
            cout << ", ";
        }
    }
    cout << "}";
    return 0;
}