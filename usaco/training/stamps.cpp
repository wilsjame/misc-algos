/*
ID: jgwilso1
PROG: stamps
LANG: C++                 
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int mxSum = 2e6;

int main() {
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);
    int k;
    cin >> k;
    int n;
    cin >> n;
    vector<int> stamp(n);
    for (int &k : stamp) {
      cin >> k;
    }
    sort(stamp.begin(), stamp.end());

    int dp[mxSum]; // dp[i] min number of stamps used to make sum i
    dp[0] = 0;
    for (int s = 1; s < mxSum; s++) {
      int mn = mxSum;
      for (int i = 0; i < n; i++) {
        if (s - stamp[i] >= 0) {
          dp[s] = dp[s - stamp[i]] + 1;
          mn = min(mn, dp[s]);
        }
      }
      dp[s] = mn;
      if (dp[s] > k) {
        cout << s - 1 << endl;
        return 0;
      }
    }

    return 0;
}
