#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    S = S.substr(0, S.length() - 1);
    
    // could use a refactor :>
    for (;;) {
        if (S.length() % 2) {
            S = S.substr(0, S.length() - 1);
        }
        else {
            string s1, s2;
            s1 = S.substr(0, S.length() / 2);
            s2 = S.substr(S.length() / 2, S.length() / 2);
            if (s1 == s2) {
                cout << S.length() << endl;
                break;
            }
            S = S.substr(0, S.length() - 1);
        }
    }

    return 0;
}
