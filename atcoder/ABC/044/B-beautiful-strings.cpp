#include <iostream>
#include <string>
using namespace std;

int main() {
	int c[26] = {};
	string s;
	cin >> s;
	for (char d : s)
		c[d - 'a']++;

	bool beautiful = true;
	for (int i = 0; i < 26; i++) {
		if (c[i]&1)
			beautiful = false;
	}
	cout << (beautiful ? "Yes" : "No");

	return 0;
}
