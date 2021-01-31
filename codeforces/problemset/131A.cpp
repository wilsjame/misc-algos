#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
	string s;
	cin >> s;
	bool change = true;
	// regardless if first letter is upper or lower
	// only care if the remaining letters are all
	// uppercase
	for (int i = 1; i < s.length(); i++) {
		if (islower(s[i])) {
			change = false;
			break;
		}
	}

	// change case of each letter
	if (change) {
		if (isupper(s[0]))
			cout << char(tolower(s[0]));
		else if (islower(s[0]))
			cout << char(toupper(s[0]));
		for (int i = 1; i < s.length(); i++) 
			cout << char(tolower(s[i]));
	}
	else 
		cout << s;
	
	return 0;
}
