#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    bool different = false;
    int count[26] = {};
    for (char c : S) {
        if (++count[c - 'a'] > 1) {
            different = true;
            break;
        }
    }
    cout << (different ? "no" : "yes") << endl;

    return 0;
}
