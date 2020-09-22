#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, X;
	cin >> N >> X;
	vector<int> price(N), pages(N);
	// note: 0 based indexed
	for (auto &k : price) cin >> k;
	for (auto &k : pages) cin >> k;

	// dp[i][x] is the maximum pages from picking among the
	// first i books for a maximum cost of x.
	// base cases: dp[0][all x] = 0 no books no pages 
	// note: 1 based indexed
	vector<vector<int>> dp(N + 1, vector<int> (X + 1, 0));

	// books 1 -> N
	for (int i = 1; i <= N; i++) {
		// sums 0 -> X
		for (int x = 0; x <= X; x++) {
			// in case we don't buy the book
			dp[i][x] = dp[i - 1][x];
			// do we have enough money to buy the book?
			if (x - price[i - 1] >= 0) {
				// we either don't buy it or do
				dp[i][x] = max(dp[i][x], dp[i - 1][x - price[i - 1]] + pages[i - 1]);
			}
		}
	}	
	cout << dp[N][X];
	
	return 0;
}
