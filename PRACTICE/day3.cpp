// #include <iostream>
// using namespace std;

// class A {
// public:
//     A(int a) {
//         cout << "Constructor A: " << a << endl;
//     }

// };

// class B : public A {
// public:
//     B(int a, int b) : A(a) {
//         cout << "Constructor B: " << b << endl;
//     }

// };

// class C : public B {
// public:
//     C(int a, int b, int c) : B(a, b) {
//         cout << "Constructor C: " << c << endl;
//     }
// };

// int main() {
//     C obj(10, 20, 30);

//     return 0;
// }


// #include <iostream>
// using namespace std;

// class A {
// public:
//     A() {
//         cout << "Constructor Called" << endl;
//     }

//     void show() {
//         cout << "Hello C++" << endl;
//     }

// };

// int main() {
//     A *ptr = new A();

//     ptr->show();
//     cout << "Hello C++ and cpp" << endl;

//     (*ptr).show();

//     // delete ptr;

//     return 0;
// }


// #include <iostream>
// using namespace std;

// class car {
// public:
//     // car() {
//     //     cout << "Constructor Called" << endl;
//     // }

//    virtual void changegear() {
//         cout << "Gear Changed" << endl;    
//     }
//     void speedup() {
//         cout << "Speed Increased" << endl;
//     }

// };

// class sportsCar : public car {
// public:
//     // sportsCar() {
//     //     cout << "Sports Car Constructor Called" << endl;
//     // }
//     void changegear() {                               // Overriding the base class method , early binding will be used here
//         cout << "Sports Car Gear Changed" << endl;
//     }
//     void speedup(int x) {
//         cout << "Sports Car Speed Increased" << x << endl;
//     }
// };

// int main() {
//     // car *ptr = new sportsCar();                       // Upcasting
//     // ptr->changegear();                                // early binding will be used here as the base class method
//     // ptr->speedup();                                   // early binding will be used here as the base class method
// // sportsCar obj;
// // obj.changegear();
// //                               // obj1.speedup();                       // method hiding will be used here as the base class method is hidden by the derived class method
// // obj.speedup(100);

// car *ptr = new sportsCar();                       // Upcasting
// ptr->changegear();                                // late binding will be used here as the base class method is virtual
// ptr->speedup();                                   // early binding will be used here as the base class method
//     return 0;
// }


#include <iostream>
using namespace std;

class A {
public:
    void show() {
        cout << "Class A" << endl;
    }
};

class B : virtual public A {
};

class C : virtual public A {
};

class D : public B, public C {
};

int main() {
    D obj;

    obj.show();

    return 0;
