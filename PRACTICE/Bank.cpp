#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;

public:
    BankAccount(int accountNumber, double balance) {
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    void deposit(double balance) {
        this->balance += balance;
    }

    void withdraw(double balance) {
        if(this->balance >= balance) {
            this->balance -= balance;
        }
        else {
            cout << "Insufficient balance" << endl;
        }
    }

    void display() {
        cout << "Account Number: " << this->accountNumber << endl;
        cout << "Balance: " << this->balance << endl;
    }
};

int main() {
    BankAccount b1(101, 5000);

    b1.deposit(1500);
    b1.withdraw(2000);

    b1.display();

    return 0;
}