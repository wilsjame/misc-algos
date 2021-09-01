/*
ID: jgwilso1
PROG: wormhole
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
using namespace std;
const int mxN = 12;

int x[mxN + 1], y[mxN + 1];
int partner[mxN + 1], to_right_of[mxN + 1];
int n;

int has_cycle() {
    for (int start = 1; start <= n; start++) {
        int pos = start;
        for (int k = 0; k < n; k++) {
            pos = to_right_of[partner[pos]];
        }
        if (pos != 0) {
            return 1; 
        }
    }
    return 0;
}

// generate all pairings of wormholes
int search() {
    int i, ans = 0;
    for (i = 1; i <= n; i++) {
        if (!partner[i]) {
            break;
        }
    }
    if (i > n) {
        return has_cycle();
    }
    for (int j = i + 1; j <= n; j++) {
        if (!partner[j]) {
            partner[i] = j;
            partner[j] = i;
            ans += search();
            partner[i] = partner[j] = 0;
        }
    }
    return ans;
}

int main() {
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[j] > x[i] && y[j] == y[i]) {
                if (!to_right_of[i] || x[j] - x[i] < x[to_right_of[i]] - x[i]) {
                    to_right_of[i] = j;
                }
            }
        }
    }
    cout << search() << endl;
    return 0;
}
