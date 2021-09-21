/*
ID: jgwilso1
PROG: hamming
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int hamming(int a, int b) {
    int d = 0;
    for (int i = 7; i >= 0; --i) {
        d += (a&(1<<i)) != (b&(1<<i));
    }
    return d;
}

int main() {
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);
    int N, B, D;
    cin >> N >> B >> D;
    vector<int> ans;
    ans.push_back(0);
    for (int i = 1; i <= 256; i++) {
        if ((int)ans.size() == N) break;
        bool ok = true;
        for (auto x : ans) {
            if (hamming(x, i) < D) {
                ok = false;
                break;
            }
        }
        if (ok) ans.push_back(i);
    }
    for (int i = 1; i <= (int)ans.size(); i++) {
        cout << ans[i-1];
        if (i == (int)ans.size() || i%10 == 0) cout << endl;
        else cout << " ";                                    
    }

    return 0;
}
