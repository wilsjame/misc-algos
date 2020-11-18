#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    int t, s;
    t = T.length();
    s = S.length();
    bool match;

    // O(S*T)
    // work backwards
    for (int i = s - t; i >= 0; i --) {
        match = true;
        for (int j = 0; j < t; j++) {
            if (S[i + j] != '?' && S[i + j] != T[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            S.replace(i, t, T);
            replace(S.begin(), S.end(), '?', 'a');
            break;
        }
    }

    cout << (match ? S : "UNRESTORABLE") << endl;

    return 0;
}
