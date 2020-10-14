#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main () {
	int n;
	cin >> n;
	ll mx = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		mx = max(mx, x);
		ans += mx - x;
	}
	cout << ans;
}

/*
int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (int &x : A) 
		cin >> x;
	ll ans = 0;
	for (int i = 0; i + 1 < n; i++) {
		if (A[i + 1] < A[i]) { 
			ans +=  A[i] - A[i + 1]; 
			A[i + 1] = A[i]; 
		}
	}
	cout << ans;

	return 0;
}
*/

