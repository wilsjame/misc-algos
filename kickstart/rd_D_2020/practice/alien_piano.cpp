#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; case_num++) {
        int k;
        cin >> k;
        vector<int> a(k);
        for (auto &x : a) {
            cin >> x;
        }
        vector<vector<int>> dp (k + 1, vector<int> (4, 10005));
        for (int i = 0; i < 4; i++) {
            dp[0][i] = 0;
        }

        // O(k * notes^2)
        for (int i = 1; i < k; i++) {
            for (int curr = 0; curr < 4; curr++) {
                for (int last = 0; last < 4; last++) {
                    int rbreak = 0;
                    if (a[i] > a[i - 1] && curr <= last) {
                        rbreak = 1;
                    }
                    else if (a[i] < a[i - 1] && curr >= last) {
                        rbreak = 1;
                    }
                    else if (a[i] == a[i - 1] && curr != last) {
                        rbreak = 1;
                    }
                    dp[i][curr] = min(dp[i - 1][last] + rbreak, dp[i][curr]);
                }
            }
        }
        int ans = 10005;
        for (int i = 0; i < 4 ; i++) {
            ans = min(ans, dp[k-1][i]);
        }

        printf("Case #%d: %d\n", case_num, ans);
    }

    return 0;
}
