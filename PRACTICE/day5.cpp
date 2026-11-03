#include <iostream>
#include<array>
using namespace std;

// template <typename T>
// class Calculator {
// public:
//     T add(T a, T b) {
//         return a + b;
//     }
// };

int main(){
    // Calculator<int> obj1;
    // Calculator<float> obj2;

    // cout << obj1.add(10, 20) << endl;
    // cout << obj2.add(2.5f, 3.5f) << endl;


    array<int,5>arr={1,2,3,4,5};
    // cout << arr[0] << arr[1] << arr[2] << arr[3] << arr[4];
   for(auto it=arr.begin() ; it!=arr.end() ; it++){
    cout<< *it << " ";
}
    return 0;
}