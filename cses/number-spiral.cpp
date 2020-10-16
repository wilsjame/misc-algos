#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll y, x;
		cin >> y >> x;

		ll mx, sq;
		mx = max(y, x);
		sq = mx * mx;
		if (y == x) {
			if (x % 2) {
				sq = sq - y + 1;
			}
			else {
				sq = sq - x + 1;
			}
		}
		else if (y > x) {
			if (y % 2 == 0) {
				sq = sq - x + 1;
			}
			else {
				sq = sq - (2 * y) + 2;
				sq = sq + x - 1;
			}
		}
		else if (x > y) {
			if (x % 2) {
				sq = sq - y + 1;
			}
			else {
				sq = sq - (2 * x) + 2;
				sq = sq + y - 1;
			}
		}
		cout << sq << endl;;
	}

	return 0;
}
