
#include <iostream>
#include "headerfile.h"
using namespace std;

int main() {
    Vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << "\nSize: " << v.size();
    cout << "\nCapacity: " << v.capacity();

    return 0;
}
