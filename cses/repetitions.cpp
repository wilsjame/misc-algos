#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
	string s;
	cin >> s;
	int ans = 1, c = 0;
	char l = 'A';
	for (char ch : s) {
		if (ch == l) {
			c++;
			ans = max(ans, c);
		}
		else {
			c = 1;
			l = ch;
		}
	}
	cout << ans;

	return 0;
}

