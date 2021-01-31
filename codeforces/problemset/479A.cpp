#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int a, b, c, ans = 0;
	cin >> a >> b >> c;

	// brute force
	ans = max(ans, a + b + c);
	ans = max(ans, a * b * c);
	ans = max(ans, a * (b + c));
	ans = max(ans, (a + b) * c);
	cout << ans;
	
	return 0;
}
