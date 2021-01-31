#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
	set <string> myset;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (myset.count(s) > 0) {
			cout << "YES\n";
		}
		else {
			myset.insert(s);
			cout << "NO\n";
		}
	}

	return 0;
}
