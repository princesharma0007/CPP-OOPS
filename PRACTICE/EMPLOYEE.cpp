#include <iostream>
using namespace std;

class Employee {
private:
    int employeeId;
    string name;
    int* scores;

public:
    Employee(int id, string n, int a, int b, int c) {
        employeeId = id;
        name = n;

        scores = new int[3];
        scores[0] = a;
        scores[1] = b;
        scores[2] = c;
    }

    Employee(const Employee &e) {
        employeeId = e.employeeId;
        name = e.name;

        scores = new int[3];

        for(int i = 0; i < 3; i++) {
            scores[i] = e.scores[i];
        }
    }

    void display() {
        cout << "ID: " << employeeId << endl;
        cout << "Name: " << name << endl;
        cout << "Scores: ";

        for(int i = 0; i < 3; i++) {
            cout << scores[i] << " ";
        }

        cout << endl;
    }

    void changeScore(int value) {
        scores[0] = value;
    }

    ~Employee() {
        delete[] scores;
    }
};

int main() {
    Employee e1(101, "Aman", 80, 85, 90);

    Employee e2 = e1;

    e2.changeScore(100);

    cout << "Employee 1:" << endl;
    e1.display();

    cout << "\nEmployee 2:" << endl;
    e2.display();

    return 0;
}