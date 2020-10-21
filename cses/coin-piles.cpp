#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int A, B;
		cin >> A >> B;
		int a, b, z;
		a = A % 3;
		b = B % 3;
		z = abs(A - B);
		if (z > min(A, B)) {
			cout << "NO\n";
		}
		else {
			if (A == 0 && B == 0) 
				cout << "YES\n";
			else if ((A > 0 && B > 0) && ((a == 0 && b == 0) || (a == 2 && b == 1) || (a == 1 && b == 2)))
				cout << "YES\n";
			else 
				cout << "NO\n";
		}
	}

	return 0;
}
