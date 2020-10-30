#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long

int main() {
	int N;
	cin >> N;
	vector<ll> A(N);
	ll sum = 0;
	for (auto &a : A) {
		cin >> a;
		sum += a;
	}
	//cerr << sum << endl;

	// d[i][j] = 1 when sum j can be constructed choosing from
	// the first i elements in the multiset A, 0 otherwise
	int dp[N + 1][sum + 1] = {};
	dp[0][0] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= sum; j++) {
			ll X = A[i - 1];
			dp[i][j] = dp[i - 1][j];
			if (j - X >= 0 && dp[i - 1][j - X] == 1) {
				dp[i][j] = 1;
			}
		}
	}

	ll ans, h = sum / 2;
	while (dp[N][h] == 0) 
		h++;
	ans = abs(sum - 2 * h);
	h = sum / 2;
	while (dp[N][h] == 0) 
		h--;
	ans = min(ans, abs(sum - 2 * h));
	cout << ans;
	
	/*
	for (int i = 0; i <= N; i++) {
		for (int j = 1; j <= sum; j++) {
			if (dp[i][j] == 1)
				printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
		}
	}
	*/

	return 0;
}
