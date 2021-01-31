#include <iostream>
#include <cmath>
using namespace std;
int main() {
	long long n, k;
	cin >> n >> k;

	// find starting point of even number sequence
	// if k is within the odd numbers, calculate odd number 2(k-1)+1
	// if k is within the even numbers, offset k to find kth even number
	// *be careful with index offsets*
	// zero based idx where even sequence begins
	long long even;
	if (n % 2) 
		even = (n + 1) / 2;
	else 
		even = n / 2; 

	if (k - 1 < even) {
		cout << 2 * (k - 1) + 1;
	}
	else {
		k -= even;
		cout << 2 * k;
	}

	return 0;
}
