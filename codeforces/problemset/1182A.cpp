#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int n;
	cin >> n;

	if (n % 2) {
		cout << 0 << endl;
	}
	else {
		// 36 262144
		// combinations
		float ans = pow(2, n / 2);
		cout << int(ans) << endl;
	}
	
	return 0;
}
