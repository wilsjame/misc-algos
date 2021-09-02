/*
ID: jgwilso1
PROG: skidesign
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    // complete search every elevation interval [0, 17], [1, 18], [2, 19], ..., [83, 100]
    vector<int> cost(84, 0);
    for (int i = 0; i + 17 <= 100; i++) {
        int lp = i;
        int rp = i + 17;
        for (int j = 0; j < n; j++) {
            if (a[j] < lp) {
                cost[i] += (lp - a[j]) * (lp - a[j]);
            }
            else if (a[j] > rp) {
                cost[i] += (a[j] - rp) * (a[j] - rp);
            }
        }
    }
    cout << *min_element(cost.begin(), cost.end()) << endl;
    return 0;
}
