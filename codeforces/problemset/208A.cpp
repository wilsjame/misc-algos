#include <iostream>
#include <string>
using namespace std;
int main() {
	string s, res;
	cin >> s;
	
	// trim WUB's
	for (int i = 0; i < int(s.size()); i++) {
		while (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B') {
			s.replace(i, 3, " ");
		}
	}

	// trim spaces
	// front
	int idx = 0;
	while (s[idx] == ' ') {
		s.erase(idx, 1);
	}
	// back
	while (s[s.length() - 1] == ' ') {
		s.erase(s.length() - 1, 1);
	}
	// middle
	for (int i = 0; i < int(s.size()); i++) {
		if (s[i] == ' ') {
			while (s[i + 1] == ' ') {
				s.erase(i + 1, 1);
			}
		}
	}
	cout << s;

	return 0;
}



