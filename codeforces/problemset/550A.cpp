#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    string s;
    cin >> s;
    vector<int> a, b;
    for (int i = 0; i + 1 < s.length(); i++) {
        string z = string() + s[i] + s[i+1];
        if (z == "AB")
            a.push_back(i);
        else if (z == "BA") 
            b.push_back(i);
    }

    if (a.empty() || b.empty()) {
        cout << "NO" << endl;
    }
    else if (*max_element(a.begin(), a.end()) - *min_element(b.begin(), b.end()) > 1) {
        cout << "YES" << endl;
    }
    else if (*max_element(b.begin(), b.end()) - *min_element(a.begin(), a.end()) > 1) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
