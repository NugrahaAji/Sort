#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {;
    int arr[] = {83, 86, 77, 15, 93, 35, 86, 92, 49, 21};
    int size = sizeof(arr)/sizeof(int);

    auto start = high_resolution_clock::now();
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
    auto stop = high_resolution_clock::now();
    auto runtime = duration_cast<nanoseconds>(stop - start);

    cout << endl;
    cout << "size: " << size << endl;
    cout << "Runtime: " << runtime.count() << " nanoseconds" << endl;

    // cout << "{";
    // for(int i = 0; i < size; i++){
    //     cout << arr[i];
    //     if(i < size - 1){
    //         cout << ", ";
    //     }
    // }
    // cout << "}";
    return 0;
}