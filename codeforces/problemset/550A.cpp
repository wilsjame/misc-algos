#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    bool checked_a = false, checked_b = false;
    for (int i = 0; i + 1 < s.length(); i++) {
        if (checked_a && checked_b) break;
        string a = string() + s[i] + s[i+1];
        if ((a == "AB" && !checked_a) || (a == "BA" && !checked_b)) {
            if (a == "AB") checked_a = true;
            if (a == "BA") checked_b = true;
            for (int j = i + 2; j + 1 < s.length(); j++) {
                string b = string() + s[j] + s[j+1];
                if ((a == "AB" && b == "BA") || (a == "BA" && b == "AB")) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
