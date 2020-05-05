/*
ID: jgwilso1
PROG: palsquare
LANG: C++                 
*/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// returns '0'-'9' for 0-9 and 'A' for 10, 'B' for 11, and so on
char convert(int n) {
    if (n >= 0 && n <= 9) {
        return char(n +'0');
    }
    // we want 10 to output A, 11 B, ...
    // char(65) = A, char(66) = B, ...
    // char(10+55) = A, char(11+55) = B, ...
    return char(n + 55);
}

// converts a number base 10 to a number base b
void numb_conv(string& r, int n, int b) {
    if (n == 0) {
        reverse(r.begin(), r.end());
        return;
    }
    // TODO
    r += convert(n % b);
    numb_conv(r, n / b, b);
}

bool is_pal(string s) {
    // okay to ignore middle char in odd length words
    for (int i=0, j=s.size()-1; i<s.size()/2; i++, j--) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    cerr << "%%%%%_program start_%%%%%\n";

    string s,t;
    int B;
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);

    cin >> B;

    for (int n = 1; n <= 300; n++) {
        s = "";
        numb_conv(s, n * n, B);
        if (is_pal(s)) {
            t = "";
            numb_conv(t, n, B);
            cout << t << " " << s << endl;
        }
    }

    return 0;
}
