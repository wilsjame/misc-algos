/*
ID: jgwilso1
PROG: pprime
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
using namespace std;

int digits(int n) {
    int cnt = 0;
    while (n) {
        n /= 10;
        cnt++;
    }
    return cnt;
}

bool prime(int n) {
    if (n < 2) return false;
    for (int x = 2; x*x <= n; x++) {
        if (n%x == 0) return false;
    }
    return true;
}

int main() {
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    int a, b;
    cin >> a >> b;
    // generate one digit palindromes
    if (digits(a) <= 1 && digits(b) >= 1) {
        for (int d1 = 1; d1 <= 9; d1+=2) {
            int p = d1;
            if (prime(p) && p >= a && p <= b) cout << p << endl;
        }
    }
    // generate two digit palindromes
    if (digits(a) <= 2 && digits(b) >= 2) {
        for (int d1 = 1; d1 <= 9; d1+=2) {
            int p = 10*d1 + d1;
            if (prime(p) && p >= a && p <= b) cout << p << endl;
        }
    }
    // generate three digit palindromes
    if (digits(a) <= 3 && digits(b) >= 3) {
        for (int d1 = 1; d1 <= 9; d1+=2) {
            for (int d2 = 0; d2 <= 9; d2++) {
                int p = 100*d1 + 10*d2 + d1;
                if (prime(p) && p >= a && p <= b) cout << p << endl;
            }
        }
    }
    // generate four digit palindromes
    if (digits(a) <= 4 && digits(b) >= 4) {
        for (int d1 = 1; d1 <= 9; d1+=2) {
            for (int d2 = 0; d2 <= 9; d2++) {
                int p = 1000*d1 + 100*d2 + 10*d2 + d1;
                if (prime(p) && p >= a && p <= b) cout << p << endl;
            }
        }
    }
    // generate five digit palindromes
    if (digits(a) <= 5 && digits(b) >= 5) {
        for (int d1 = 1; d1 <= 9; d1+=2) {
            for (int d2 = 0; d2 <= 9; d2++) {
                for (int d3 = 0; d3 <= 9; d3++) {
                    int p = 10000*d1 + 1000*d2 + 100*d3 + 10*d2 + d1;
                    if (prime(p) && p >= a && p <= b) cout << p << endl;
                }
            }
        }
    }
    // generate six digit palindromes
    if (digits(a) <= 6 && digits(b) >= 6) {
        for (int d1 = 1; d1 <= 9; d1+=2) {
            for (int d2 = 0; d2 <= 9; d2++) {
                for (int d3 = 0; d3 <= 9; d3++) {
                    int p = 100000*d1 + 10000*d2 + 1000*d3 + 100*d3 + 10*d2 + d1;
                    if (prime(p) && p >= a && p <= b) cout << p << endl;
                }
            }
        }
    }
    // generate seven digit palindromes
    if (digits(a) <= 7 && digits(b) >= 7) {
        for (int d1 = 1; d1 <= 9; d1+=2) {
            for (int d2 = 0; d2 <= 9; d2++) {
                for (int d3 = 0; d3 <= 9; d3++) {
                    for (int d4 = 0; d4 <= 9; d4++) {
                        int p = 1000000*d1 + 100000*d2 + 10000*d3 + 1000*d4 + 100*d3 + 10*d2 + d1;
                        if (prime(p) && p >= a && p <= b) cout << p << endl;
                    }
                }
            }
        }
    }
    // generate eight digit palindromes
    if (digits(a) <= 8 && digits(b) >= 8) {
        for (int d1 = 1; d1 <= 9; d1+=2) {
            for (int d2 = 0; d2 <= 9; d2++) {
                for (int d3 = 0; d3 <= 9; d3++) {
                    for (int d4 = 0; d4 <= 9; d4++) {
                        int p = 10000000*d1 + 1000000*d2 + 100000*d3 + 10000*d4 + 1000*d4 + 100*d3 + 10*d2 + d1;
                        if (prime(p) && p >= a && p <= b) cout << p << endl;
                    }
                }
            }
        }
    }
    return 0;
}
