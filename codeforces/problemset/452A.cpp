#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    vector<string> v = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
    string S;
    int n;
    cin >> n >> S;

    for (auto s : v) {
        bool found = true;
        for (int i = 0; i < s.length() || i < n; i++) {
            if (S[i] != '.' && S[i] != s[i] ) {
                found = false;
                break;
            }
        }
        if (found) {
            cout << s;
            break;
        }
    }

    return 0;
}
