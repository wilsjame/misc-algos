#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

// O(10^(m + 1) - 1
// ~ 1e101 - 1 permutations x_x
int main() {
	int m, s;
	cin >> m >> s;
	vector<int> a(100, 0);
	a[100 - m] = 1;
	// tens place
	int idx = 98;
	while (1) {
		if (accumulate(a.begin() + (100 - m), a.end(), 0) > s || idx < 0) {
			cout << "-1 -1";
			break;
		}
		else if (accumulate(a.begin() + (100- m), a.end(), 0) == s) {
			for (int i = 100 - m; i < 100; i++) 
				cout << a[i];
			cout << " ";
			sort(a.rbegin(), a.rend());
			for (int i = 0; i < m; i++)
				cout << a[i];
			break;
		}
		// keep searching, increment number
		else {
			if (++a[99] == 10) {
				a[99] = 0;
				bool carry = true;
				idx = 98;
				while (carry) {
					if (++a[idx] == 10)
						a[idx--] = 0;
					else 
						carry = false;
				}
			};
		}
	}

	return 0;
}
