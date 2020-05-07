/*
ID: jgwilso1
PROG: palsquare
LANG: C++                 
*/

#include <iostream>
#include <string>

using namespace std;

// put the base b representation of n into s
void numb_conv(string& s, int n, int b) {
    if (n == 0) {
        s = "";
        return;
    }
    numb_conv(s, n / b, b);
    s += "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n % b];
}

bool is_pal(string s) {
    // okay to ignore middle char if odd length 
    for (int i=0, j=s.size()-1; i<s.size()/2; i++, j--) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s,t;
    int B;
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);

    cin >> B;

    for (int n = 1; n <= 300; n++) {
        numb_conv(s, n * n, B);
        if (is_pal(s)) {
            numb_conv(t, n, B);
            cout << t << " " << s << endl;
        }
    }

    return 0;
}
