// helpful maths
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> v;
    int c1 = 0, c2 = 0, c3 = 0;
    string s;
    cin >> s;

    // O(3n)
    for (auto ch : s) {
        if (ch == '+') continue;
        if (ch == '1') c1++;
        if (ch == '2') c2++;
        if (ch == '3') c3++;
    }
    for (int i = 0 && c1 != 0; i < c1; i++) {
        v.push_back(1);
    }
    for (int i = 0 && c2 != 0; i < c2; i++) {
        v.push_back(2);
    }
    for (int i = 0 && c3 != 0; i < c3; i++) {
        v.push_back(3);
    }
    for (int i = 0; i < v.size() - 1; i++) {
        cout << v[i] << "+";
    }
    cout << v[v.size() - 1] << endl;

    // O(3nlogn)
    /*
    for (auto ch : s ) {
        if (ch == '+') continue;
        v.push_back(ch - 48);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; i++) {
        cout << v[i] << "+";
    }
    cout << v[v.size() - 1] << endl;
    */
    
    return 0;
}
