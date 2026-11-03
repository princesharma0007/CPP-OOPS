#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;

    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);

    cout << "Top: " << pq.top() << endl;
    cout << "pop: " << pq.top() << endl;
    pq.pop();
    cout << "Top: " << pq.top() << endl;

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
     while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }


    return 0;
}
