#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main () {
	int n;
	cin >> n;
	if (n == 2 || n == 3) {
		cout << "NO SOLUTION";
	}
	else {
		for (int even = 2; even <= n; even += 2) 
			cout << even << " ";
		for (int odd = 1; odd <= n; odd += 2) 
			cout << odd << " ";
	}

	return 0;
}
