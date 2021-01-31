#include <iostream>
using namespace std;
int main() {
	int n; 
	cin >> n;

	// brute force xD n is only [1,1000]
	bool lucky = false;
	for (int i : {4, 7, 44, 47, 74, 77, 444, 447, 474, 744, 777, 774, 747, 477}) {
		if (n % i == 0) {
			lucky = true;
			break;
		}
	}
	lucky ? cout << "YES" : cout << "NO";

	return 0;
}
