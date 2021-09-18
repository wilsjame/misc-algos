/*
ID: jgwilso1
PROG: frac1
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;

// Euclid's
int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(a%b, b);
}

int main() {
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);
    int n;
    cin >> n;
    map<float, pair<int, int>> m;
    for (int den = 1; den <= n; den++) {
        for (int num = 0; num <= den; num++) {
            int currnum = num / gcd(num, den);
            int currden = den / gcd(num, den);
            m[(float)currnum/currden] = {currnum, currden};
        }
    }
    for (auto k : m) {
        cout << k.second.first << "/" << k.second.second << endl;
    }
    
    return 0;
}
