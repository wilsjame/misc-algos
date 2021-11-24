/*
ID: jgwilso1
PROG: runround
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

bool isrunround(long n) {
    string s = to_string(n);
    int N = s.size();
    bool visited[N] = {};
    int pos = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[pos] || s[pos] == '0') 
            return false;
        visited[pos] = true;
        pos = ((s[pos]-'0')+pos) % N; // walk
    }
    // end at start
    if (pos != 0) return false; 
    // unique digits
    int cnt[10] = {};
    while (n) {
        if (++cnt[n%10] > 1) return false;
        n /= 10;
    }

    return true;
}

int main() {
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);
    long n;
    cin >> n;
    while (!isrunround(++n));
    cout << n << endl;

    return 0;
}
