#include <iostream>
#include <vector>
using namespace std;
int const mod = 1e9 + 7;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	// dp[i][x]
	// number of valid arrays up to index i
	// such that the last element is x.
	// reoccurrence =>
	// dp[i][x] = 0 when a_i != 0 && a_i != x
	// dp[i][x] = dp[i-1][x-1] + dp[i-1][x] + dp[x-1][x+1] when a_i == 0 || a_i == x
	// base case => first element
	// dp[1][x] = 1 when a_1 == 0 || a_1 == x
	// dp[1][x] = 0 when a_1 != x
	
	// note: m + 2 so when x = m, [x + 1] will be zero instead of out of bounds
	vector<vector<int>> dp(n + 1, vector<int> (m + 2, 0));
	for (int x = 1; x <= m; x++) {
		if (a[1] == 0 || a[1] == x) {
			dp[1][x] = 1;
		}
		else { 
			dp[1][x] = 0;
		}
	}

	for (int i = 2; i <= n; i++) {
		for (int x = 1; x <= m; x++) {
			if (a[i] == 0 || a[i] == x) {
				dp[i][x] = ((dp[i - 1][x - 1] + dp[i - 1][x])%mod + dp[i - 1][x + 1])%mod; 
			}
			else {
				dp[i][x] = 0;
			}
		}
	}

	// total count will be the sum of dp[n][x] for x = [1,m]
	int cnt = 0;
	for (int x = 1; x <= m; x++) {
		cnt = (cnt + dp[n][x]) % mod;
	}
	cout << cnt << endl;

	return 0;
}
