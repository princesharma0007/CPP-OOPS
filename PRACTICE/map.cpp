#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> mp;
    mp[2] = "Aman";
    mp[4] = "Aryan";
    mp[1] = "Prince";
    mp[3] = "Meet";

    cout << "Using Range-Based Loop:\n";

    for (auto &it : mp) {
        cout << it.first << " -> " << it.second << endl;
    }

    cout << "\nUsing Iterator:\n";

    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " -> " << it->second << endl;
    }

    return 0;
}
