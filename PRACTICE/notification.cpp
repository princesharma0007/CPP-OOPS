#include <iostream>
using namespace std;

class Notification {
public:
    virtual void send() {
        cout << "General Notification" << endl;
    }

};

class Email : public Notification {
public:
    void send() {
        cout << "Email Notification Sent" << endl;
    }
};

class SMS : public Notification {
public:
    void send() {
        cout << "SMS Notification Sent" << endl;
    }
};

class WhatsApp : public Notification {
public:
    void send(){
        cout << "WhatsApp Notification Sent" << endl;
    }
};

int main() {
    Email e;
    SMS s;
    WhatsApp w;
    Notification *ptr;
    int choice;

    cout << "1. Email" << endl;
    cout << "2. SMS" << endl;
    cout << "3. WhatsApp" << endl;

    cout << "Enter Choice: ";
    cin >> choice;

    if (choice == 1) {
        ptr = &e;
    }
    else if (choice == 2) {
        ptr = &s;
    }
    else if (choice == 3) {
        ptr = &w;
    }
    else {
        cout << "Invalid Choice" << endl;
        return 0;
    }

    ptr->send();

    return 0;
}