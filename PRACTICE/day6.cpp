#include <iostream>
using namespace std;

void grow(int *&arr, int &capacity) {
    int newCapacity = capacity * 2;
    int *newArr = new int[newCapacity];

    for (int i = 0; i < capacity; i++) {
        newArr[i] = arr[i];
    }

    delete[] arr;

    arr = newArr;
    capacity = newCapacity;
}

int main() {
    int capacity = 2;
    int *arr = new int[capacity];

    arr[0] = 10;
    arr[1] = 20;

    grow(arr, capacity);

    arr[2] = 30;

    cout << "Capacity: " << capacity << endl;

    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}