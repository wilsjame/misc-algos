#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 100005
#define ll long long
int main() {
    int n;
    cin >> n;
    vector<ll> a, cnt(INF+1,0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
        cnt[x]++;
    }
    // dp[x] is the max value if x was the last number picked
    vector<ll> dp(INF+1,0);
    dp[a[0]] = a[0] * cnt[a[0]];
    for (int i = 1; i < 100000 + 1; i++) {
        dp[i] = max(cnt[i]*i + dp[max(0,i-2)], dp[i-1]);
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}
