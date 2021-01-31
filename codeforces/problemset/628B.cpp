#include <iostream>
#include <string>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string S;
	cin >> S;

	ll total = 0, N = S.size();
	for (int i = 0; i < N; i++) {
		if (S[i] % 4 == 0) 
			total++;
	}
	// 4 divisibility rule 
	// last two digits must be divisible by 4
	for (int i = 0; i + 1 < N; i++) {
		int k;
		k = 10 * (S[i] - '0') + S[i + 1] - '0';
		if (k % 4 == 0)
			total += i + 1;
	}	
	cout << total;

	return 0;
}
