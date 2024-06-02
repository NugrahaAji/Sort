#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {;
    int arr[] = {83, 86, 77, 15, 93, 35, 86, 92, 49, 21};
    int size = sizeof(arr)/sizeof(int);

    auto start = high_resolution_clock::now();
    for (int i = 1; i < size; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
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