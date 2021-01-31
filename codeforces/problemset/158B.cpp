#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, res = 0;
	cin >> n;
	vector<int> one, two, three;
	for (int k, i = 0; i < n; i++) {
		cin >> k;
		if (k == 1) one.push_back(k);
		else if (k == 2) two.push_back(k); 
		else if (k == 3) three.push_back(k);
		else res++;
	}
	// greedy, place groups of one with groups of three and  two first
	while (!three.empty()) {
		if (one.empty()) {
			three.pop_back();
		}
		else { 
			three.pop_back(); one.pop_back();
		}
		res++;
	}
	while (!two.empty()) {
		if (two.size() >= 2) {
			two.pop_back(); two.pop_back();
		}
		else if (one.size() >= 2) {
			two.pop_back(); one.pop_back(); one.pop_back();
		}
		else if (one.size() > 0) {
			two.pop_back(); one.pop_back();
		}
		else {
			two.pop_back();
		}
		res++;
	}
	// remaining ones, if any
	res += one.size() / 4;
	if (one.size() % 4) {
		res++;
	}

	cout << res;

	return 0;
}
