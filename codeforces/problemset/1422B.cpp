#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
void test_case() {
	int N, M;
	cin >> N >> M;
	vector<vector<long long>> A(N, vector<long long> (M));
	for (auto &row : A) {
		for (auto &a : row) {
			cin >> a;
		}
	}

	long long cnt = 0;
	// N,M + 1 guarantees we will iterate to middle if N,M is odd
	for (int i = 0; i < (N + 1) / 2; i++) {
		for (int j = 0; j < (M + 1) / 2; j++) {
			// coordinates of opposite corners
			int oi, oj;
			oi = N - 1 - i;
			oj = M - 1 - j;
			// use set to avoid duplicates
			set<pair<int, int>> coords;
			coords.emplace(i, j);
			coords.emplace(i, oj);
			coords.emplace(oi, j);
			coords.emplace(oi, oj);
			vector<long long> v;

			for (auto pt : coords) {
				v.push_back(A[pt.first][pt.second]);
			}
			
			sort(v.begin(), v.end());
			// imagine number line: a-b-c-d spaced: -x-y-z-
			// cost to b and c from other elements is lowest: x (after canceling terms)
			// so v.size() / 2 will guarantee median for even and odd sizes
			long long median = v[v.size() / 2];

			for (auto k : v) {
				cnt += abs(k - median); 
			}
		}
	}
	cout << cnt << endl;

	return;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		test_case();
	}
}
