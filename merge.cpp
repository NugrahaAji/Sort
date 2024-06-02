#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void merge(int * arr, int low, int mid, int high) {
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;

    int temp[20];

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int * arr, int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[] = {83, 86, 77, 15, 93, 35, 86, 92, 49, 21};
    int size = sizeof(arr)/sizeof(int);

    auto start = high_resolution_clock::now();
    mergeSort(arr, 0, size - 1);
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