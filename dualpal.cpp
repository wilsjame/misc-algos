/*
ID: jgwilso1
PROG: dualpal
LANG: C++                 
*/

#include <iostream>
#include <string>

using namespace std;

// put the base b representation of n into s
void numbconv(string& s, int n, int b) {
    if (n == 0) {
        s = "";
        return;
    }
    numbconv(s, n / b, b);
    s += "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n % b];
}

// is s a palindrome?
bool ispal(string& s) {
    for (int i = 0, j = s.size()-1; i < s.size()/2; i++, j--) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    cerr << "%%%___program start___%%%\n";
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);

    int N, S, count;
    string s;

    cin >> N;
    cin >> S;

    for (++S; N > 0; S++) {
        count = 0;

        for (int b = 2; b <= 10; b++) {
            numbconv(s, S, b);
            if (ispal(s)) {
                count++;
            }
            if (count >= 2) {
                cout << S << endl;
                N--;
                break;
            }
        }

    }

    return 0;
}
