#include <iostream>
#include <string>
#include <algorithm>
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
		for (int i = 0; i < 26; i++) 
			if (m[i] % 2 == 0) 
				for (int j = 0; j < m[i] / 2; j++)
						res += char(i + 'A');
		cout << res;
		if (odd_cnt > 0)
			while (m[odd_idx]-- > 0) 
				cout << char(odd_idx + 'A');
		reverse(res.begin(), res.end());
		cout << res;
	}

	return 0;
}
