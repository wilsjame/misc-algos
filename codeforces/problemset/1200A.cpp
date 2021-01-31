#include <iostream>
#include <vector>
using namespace std;
int main() {
	char c;
	int n;
	cin >> n;
	vector<int> a(10, 0);

	for (int i = 0; i < n; i++) {
		cin >> c;
		if (c == 'R') {
			for (int i = a.size() - 1; i >= 0; i--) {
				if (a[i] == 0) {
					a[i] = 1;
					break;
				}
			}
		}
		else if (c == 'L') {
			for (int i = 0; i < a.size(); i++) {
				if (a[i] == 0) {
					a[i] = 1;
					break;
				}
			}
		}
		else {
			a[c - 48] = 0;
		}
	}
	for (auto x : a) {
		cout << x;
	}
	cout << endl;

	return 0;
}

