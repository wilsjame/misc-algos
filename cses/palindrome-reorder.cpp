#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;
	int m[26] = {};
	for (char c : S) 
		m[c - 'A']++;
	int odd_idx, odd_cnt = 0;
	for (int i = 0; i < 26; i++) 
		if (m[i] % 2) {
			odd_cnt++;
			odd_idx = i;
		}
	if (odd_cnt > 1)
		cout << "NO SOLUTION";
	else {
		string res;
		if (odd_cnt > 0)
			while (m[odd_idx]-- > 0) 
				res += char(odd_idx + 'A');
		for (int i = 0; i < 26; i++) 
			while (m[i] > 0) {
				res = char(i + 'A') + res;
				res = res + char(i + 'A');
				m[i] -= 2;
			}
		cout << res;
	}

	return 0;
}
