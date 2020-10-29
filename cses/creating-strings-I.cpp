#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<string> V;
	string S;
	cin >> S;

	sort(S.begin(), S.end());
	do {
		V.push_back(S);
	} while (next_permutation(S.begin(), S.end()));

	cout << V.size() << endl;
	for (auto s : V) 
		cout << s << endl;

	return 0;
}
