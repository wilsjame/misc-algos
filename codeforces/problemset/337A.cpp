#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e9+5;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (auto &x : a) cin >> x;
	sort(a.begin(), a.end());

	// sliding window
	int ans = INF;
	for (int i = 0; i + n <= m; i++) {
		ans = min(ans, a[i + n - 1] - a[i]);
		//cerr << a[i + n - 1] << " " << a[i] << endl;
	}
	cout << ans;

	return 0;
}
