#include <iostream>
#include <vector>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &k : a) cin >> k;

		// bubble sort maximum inversions
		// is n(n-1)/2 when the array is
		// completely reversed.
		// allowed n(n-1)/2 - 1 inversions
		// so "NO" case is when the the array is completely reversed
		bool ok = false;
		for (int i = 1; i < n && !ok; i++) 
			if (a[i-1] <= a[i]) 
				ok = true;
				
		ok ? cout << "YES\n" : cout << "NO\n";
	}

	return 0;
}

