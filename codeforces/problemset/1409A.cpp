#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;

		int dif, res = 0;
		dif = abs(a - b); 
		res += dif / 10;
		dif %= 10;
		if (dif > 0) 
			res++;
		cout << res << endl;
	}

	return 0;
}
