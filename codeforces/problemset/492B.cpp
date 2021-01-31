#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, l;
	cin >> n >> l;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	sort(a.begin(), a.end());
	// beginning and end of street
	float dist = max(a[0], l - a[n - 1]);
	for (int i = 0; i + 1 < n; i++) {
		dist = max(dist, float((a[i + 1] - a[i])) / 2);
	}
	cout << fixed << dist;
	
	return 0;
}
