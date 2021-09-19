/*
ID: jgwilso1
PROG: sort3
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int mxN = 1000+5;

int main() {
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0 ; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a.begin(), a.end());
    int one = mxN;
    int two = mxN;
    int three = mxN;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1 && one == mxN) one = i;
        if (a[i] == 2 && two == mxN) two = i;
        if (a[i] == 3 && three == mxN) three = i;
    }
    // greedy works!
    // swap 1's in the 2 position with 2's in 1 position
    for (int i = one; i < two; i++) {
        if (b[i] == 2) {
            cerr << "here! ";
            for (int j = two; j < three; j++) {
                if (b[j] == 1) {
                    swap(b[i], b[j]);
                    ans++;
                    break;
                }
            }
        }
    }
    // swap 2's in the 3 position with 3's in the 2 position
    for (int i = two; i < three; i++) {
        if (b[i] == 3) {
            for (int j = three; j < n; j++) {
                if (b[j] == 2) {
                    swap(b[i], b[j]);
                    ans++;
                    break;
                }
            }
        }
    }
    // swap 3's in the 1 position with 1's in the 3 position
    for (int i = three; i < n; i++) {
        if (b[i] == 1) {
            for (int j = one; j < two; j++) {
                if (b[j] == 3) {
                    swap(b[i], b[j]);
                    ans++;
                    break;
                }
            }
        }
    }
    // leftover mismatches are three numbers in wrong spots
    // and it takes two operations to move them in correct spots
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += a[i] != b[i];
    }
    cout << ans + (cnt/3)*2 << endl;
    
    return 0;
}
