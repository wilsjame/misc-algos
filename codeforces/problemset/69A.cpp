#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int x = 0, y = 0, z = 0;
	for (int a, b, c, i = 0; i < n; i++) {
		cin >> a >> b >> c;
		x += a;
		y += b;
		z += c;
	}
	x == 0 && y == 0 && z == 0 ? cout << "YES" : cout << "NO";

	return 0;
}
