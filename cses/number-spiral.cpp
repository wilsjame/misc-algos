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
		// either the top most cell or the left most cell is a square.
		// if y and x are equal
		//  if odd top most cell is square
		//  else if even left most cell is square
		//
		//  if y is greater than x were on the left side of the main diagonal 
		//  else if x is greater than y were on the right side of the main diagonal
		//
		//   if y is even we have a square in the left most
		//   if y is odd we do not have a square in the left most
		//   simlilar logic if x is even or odd
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
