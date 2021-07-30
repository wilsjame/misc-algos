#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool ok(vector<int>d, int dt, int k) {
    int ksum = 0;
    for (int di : d) {
        int ki = ((di + dt - 1) / dt) - 1;
        ksum += ki;
    }
    return ksum <= k;
}
int main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n, k;
        cin >> n >> k;
        int m[n];
        for (int i = 0; i < n; i++) {
            cin >> m[i];
        }
        vector<int> d;
        for (int i = 1; i < n; i++) {
            d.push_back(m[i] - m[i - 1]);
        }
        // binary search where ok(dt) changes
        int l = 1, r = *max_element(d.begin(), d.end());
        while (l <= r) {
            int dt = (l + r) / 2; // mid
            if (ok(d, dt, k)) {
                r = dt - 1; 
            }
            else {
                l = dt + 1;
            }
        }
        int ans = l; // minimum dt where ksum is closest to K without being greater
        printf("Case #%d: %d\n", tt, ans);
    }
    return 0;
}

// Analysis
// determine for each session something related to K
// for example 10 -> 20 
// how many k's to achieve a specific difficulty
// we want difficulty 11?
// 20 - 10  = ceil(10 / 11) - 1 = 0
// we want difficulty 10?
//  20 - 10 = ceil(10 / 10) - 1 = 0
// we want difficulty 9? 
//  20 - 10 = ceil(10 / 9) - 1 = 1
//  *                          X   *
//  10 11 12 13 14 15 16 17 18 19 20 
//  so number of k's needed to achieve difficulity dt is:
//  ki = ceil(di / dt) - 1
//  we want to minimize dt
//  ki increases as dt decreases!
//  find the minimum dt where ksum is closest
//  or equal to K without going over.
//  we could linear search dt, but better is binary search dt
//  for each jump calculate ksum O(N)
//  => log(10^9) * N
