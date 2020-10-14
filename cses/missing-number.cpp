#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main() {
	ll n, sum = 0;
	cin >> n;

	for (int i = 0; i < n -1; i++) {
		ll x;
		cin >> x;
		sum += x;
	}

	cout << (n*(n + 1) / 2) - sum;

	return 0;
}

/*
int main() {
	int n;
	cin >> n;
	vector<int> A(n + 1, 0);
	for (int i = 0; i < n - 1; i++) {
		int k;
		cin >> k;
		A[k] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (A[i] != 1) {
			cout << i;
			break;
		}
	}
	
	return 0;
}
*/
