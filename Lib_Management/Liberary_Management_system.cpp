#include <ctime>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class LibraryItem{
public:
    virtual void display()= 0;
};

class Book : public LibraryItem{
public:
    int id, copies;
    string title, author;

    Book(int i, string t, string a, int c){
        id = i;
        title = t;
        author = a;
        copies = c;
    }

    void display() override{
        cout << "ID: " << id
             << "\nTitle: " << title
             << "\nAuthor: " << author
             << "\nCopies: " << copies << endl;
    }
};

class Member{
public:
    int id;
    string name;
    vector<int> bookIds;
    vector<int> issueDays;

    Member(int i, string n){
        id = i;
        name = n;
    }

    void display() {
        cout << "Member ID: " << id << endl;
        cout << "Name: " << name << endl;

        for (int i = 0; i < bookIds.size(); i++){
            cout << "Book ID: " << bookIds[i]
                 << " Due Day: " << issueDays[i] + 15 << endl;
        }
    }
};

class Library{
public:
    vector<Book> books;
    vector<Member> members;

    void addBook();
    void addMember();
    void displayBooks();
    void searchBook();
    void issueBook();
    void returnBook();
    void viewMember();
    void calculateFine();
};

void Library::addBook() {
    int id, copies;
    string title, author;

    cout << "Book ID: ";
    cin >> id;
    if(id < 0) {
      cout << "Invalid ID!\n";
        return;
    }

    for (auto &b : books){
        if (b.id == id){
            cout << "Book ID already exists!\n";
            return;
        }
    }

cout << "Title: ";
cin >> ws;
getline(cin, title);

cout << "Author: ";
getline(cin, author);

    cout << "Copies: ";
    cin >> copies;

    if (copies < 0) {
        cout << "Invalid copies!\n";
        return;
    }

    books.push_back(Book(id, title, author, copies));
    cout << "Book Added!\n";
}

void Library::addMember(){
    int id;
    string name;

    cout << "Member ID: ";
    cin >> id;

    for (auto &m : members) {
        if (m.id == id) {
            cout << "Member already exists!\n";
            return;
        }
    }

    cout << "Name: ";
    getline(cin, name);

    members.push_back(Member(id, name));
    cout << "Member Registered!\n";
}

void Library::displayBooks(){
    if (books.empty()) {
        cout << "No Books Available!\n";
        return;
    }

    for (auto &b : books) {
        b.display();
        cout << "---------------\n";
    }
}

void Library::searchBook(){
    int choice;
    cout << "1. Search by ID\n2. Search by Title\n";
    cin >> choice;

    if (choice == 1) {
        int id;
        cout << "Book ID: ";
        cin >> id;

        for (auto &b : books) {
            if (b.id == id) {
                b.display();
                return;
            }
        }
    }
    else if (choice == 2) {
    string title;
    cout << "Title: ";
    cin >> ws;
    getline(cin, title);

    for (auto &b : books) {
        if (b.title == title) {
            b.display();
            return;
        }
    }
}

    cout << "Book Not Found!\n";
}

void Library::issueBook(){
    int mid, bid, day;

    cout << "Member ID: ";
    cin >> mid;
    cout << "Book ID: ";
    cin >> bid;

    for (auto &m : members){
        if (m.id == mid) {

            if (m.bookIds.size() >= 3){
                cout << "Borrowing Limit Reached!\n";
                return;
            }

            for (int id : m.bookIds){
                if (id == bid) {
                    cout << "Already Borrowed!\n";
                    return;
                }
            }

            for (auto &b : books){
                if (b.id == bid) {
                    if (b.copies <= 0) {
                        cout << "Book Not Available!\n";
                        return;
                    }

                    cout << "Issue Day: ";
                    cin >> day;

                    if (day < 0) {
                        cout << "Invalid Day!\n";
                        return;
                    }
                    // time_t now = time(nullptr);
                    // int day = now / 86400;

                    m.bookIds.push_back(bid);
                    m.issueDays.push_back(day);
                    b.copies--;

                    cout << "Book Issued Successfully!\n";
                    cout << "Due Day: " << day + 15 << endl;
                    return;
                }
            }

            cout << "Book Not Found!\n";
            return;
        }
    }

    cout << "Member Not Registered!\n";
}

void Library::returnBook(){
    int mid, bid, day;

    cout << "Member ID: ";
    cin >> mid;
    cout << "Book ID: ";
    cin >> bid;

    for (auto &m : members) {
        if (m.id == mid) {
            for (int i = 0; i < m.bookIds.size(); i++) {
                if (m.bookIds[i] == bid) {
                    cout << "Return Day: ";
                    cin >> day;

                    // time_t now = time(nullptr);
                    // int day = now / 86400;

                    if (day < m.issueDays[i]) {
                        cout << "Invalid Return Day!\n";
                        return;
                    }

                    int late = day - (m.issueDays[i] + 15);
                    int fine = late > 0 ? late * 5 : 0;

                    for (auto &b : books) {
                        if (b.id == bid) {
                            b.copies++;
                            break;
                        }
                    }

                    m.bookIds.erase(m.bookIds.begin() + i);
                    m.issueDays.erase(m.issueDays.begin() + i);

                    cout << "Book Returned!\n";
                    cout << "Fine: Rs. " << fine << endl;
                    return;
                }
            }

            cout << "Book Not Issued!\n";
            return;
        }
    }

    cout << "Member Not Found!\n";
}

void Library::viewMember(){
    int id;
    cout << "Member ID: ";
    cin >> id;

    for (auto &m : members) {
        if (m.id == id) {
            m.display();
            return;
        }
    }

    cout << "Member Not Found!\n";
}

void Library::calculateFine(){
    int mid, bid, day;

    cout << "Member ID: ";
    cin >> mid;
    cout << "Book ID: ";
    cin >> bid;

    for (auto &m : members) {
        if (m.id == mid) {
            for (int i = 0; i < m.bookIds.size(); i++){
                if (m.bookIds[i] == bid) {
                    cout << "Current Day: ";
                    cin >> day;

                    // time_t now = time(nullptr);
                    // int day = now / 86400;

                    if (day < m.issueDays[i]) {
                        cout << "Invalid Day!\n";
                        return;
                    }

                    int late = day - (m.issueDays[i] + 14);
                    int fine = late > 0 ? late * 5 : 0;

                    cout << "Fine: Rs. " << fine << endl;
                    return;
                }
            }

            cout << "Book Not Borrowed!\n";
            return;
        }
    }

    cout << "Member Not Found!\n";
}

int main(){
    Library lib;
    int choice=0;

    do{
        cout << "\n===== LIBRARY MANAGEMENT =====\n";
        cout << "1. Add Book\n";
        cout << "2. Register Member\n";
        cout << "3. Display Books\n";
        cout << "4. Search Book\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. View Member\n";
        cout << "8. Calculate Fine\n";
        cout << "9. Exit\n";
        cout << "Enter Choice: ";
         if (!(cin >> choice)){
              if (cin.eof()){
               break;
             }

         cin.clear();
         cin.ignore(10000, '\n');

         cout << "Invalid Input! Enter a number.\n";
         continue;
}
   
        switch (choice){
            case 1: lib.addBook(); break;
            case 2: lib.addMember(); break;
            case 3: lib.displayBooks(); break;
            case 4: lib.searchBook(); break;
            case 5: lib.issueBook(); break;
            case 6: lib.returnBook(); break;
            case 7: lib.viewMember(); break;
            case 8: lib.calculateFine(); break;
            case 9: cout << "Thank You!\n"; break;
            default: cout << "Invalid Choice!\n";
        }

    }while(choice != 9);

    return 0;
}
