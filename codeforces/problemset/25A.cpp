#include <iostream>
#include <vector>
using namespace std;
// O(2n) ~> O(n)
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<int> even, odd;
	for (auto k : a) {
		k % 2 ? odd.push_back(k) : even.push_back(k);
	}

	int target;
	odd.size() == 1 ? target = odd[0] : target = even[0];
	for (int i = 0; i < n; i++) {
		if (a[i] == target) {
			cout << i + 1;
			break;
		}
	}

	return 0;
}
