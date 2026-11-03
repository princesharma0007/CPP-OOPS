#include <iostream>
using namespace std;

class vecotr{

};
#include <iostream>
using namespace std;

class Vector {
private:
    int *arr;
    int sz;
    int cap;

    void grow() {
        int newCap = cap * 2;
        int *newArr = new int[newCap];

        for (int i = 0; i < sz; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        cap = newCap;
    }

public:
    Vector() {
        sz = 0;
        cap = 2;
        arr = new int[cap];
    }

    void push_back(int value) {
        if (sz == cap) {
            grow();
        }

        arr[sz] = value;
        sz++;
    }

    void pop_back() {
        if (sz == 0) {
            cout << "Vector is empty\n";
            return;
        }

        sz--;
    }

    int size() {
        return sz;
    }

    int capacity() {
        return cap;
    }

    int& operator[](int index) {
        return arr[index];
    }

    void display() {
        for (int i = 0; i < sz; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Vector() {
        delete[] arr;
    }
};

int main() {
    Vector v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    v.display();

    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    v.pop_back();

    v.display();

    cout << "Element at index 1: " << v[1] << endl;

    return 0;
}
