
#include <iostream>
using namespace std;

class dummy {
public:
    int a, b;
    int *p;

 dummy() {
        a = 0;
        b = 0;
        p = nullptr;
    }

    void setter(int x, int y, int z) {
        a = x;
        b = y;
        p = new int(z);
    }

    dummy(const dummy &obj) {
        a = obj.a;
        b = obj.b;
        p = new int(*obj.p);
    }

    void display() {
        cout << a << " " << b << " " << *p << endl;
    }

};

int main() {
    dummy d1;
    d1.setter(10, 20, 30);

    dummy d2 = d1;

    cout << "Before Modification:\n";
    d1.display();
    d2.display();

    *d2.p = 100;

    cout << "\nAfter Modification:\n";
    d1.display();
    d2.display();

    return 0;
}
