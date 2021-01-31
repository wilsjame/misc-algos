#include <iostream>
using namespace std;
int main() {
	int n, b, p;
	cin >> n >> b >> p;

	// 1 winner so n - 1 players will be eliminated
	// n - 1 eliminations require n - 1 matches
	int x, y;
	x = (n - 1) * (2 * b + 1);
	y = n * p;
	cout << x << " " << y;

	return 0;
}
