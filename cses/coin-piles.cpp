#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int A, B;
		cin >> A >> B;
		int s, mn, mx;
		s = A + B;
		mn = min(A, B);
		mx = max(A, B);
		s % 3 == 0 && 2 * mn >= mx ? cout << "YES\n" : cout << "NO\n";
	}

	return 0;
}
