#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N; 
	cin >> N;
	vector<int> A(N);
	for (auto &k : A)
		cin >> k;
	sort(A.begin(), A.end());
	long long ans = 0, mx = A[N - 1];
	for (auto k : A)
		ans += mx - k;
	cout << ans;

	return 0;
}

