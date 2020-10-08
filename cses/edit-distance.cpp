#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& distance) {
	// base case 
	// no more replacing, only need to add or remove the remaining characters
	if (i == (int)s1.length() || j == (int)s2.length()) {
		return max((int)s1.length() - i, (int)s2.length() - j);
	}

	// memo
	if (distance[i][j] != -1) {
		return distance[i][j];
	}

	if (s1[i] == s2[j]) {
		distance[i][j] = solve(i + 1, j + 1, s1, s2, distance);
	}
	else {
		// operations are done on s1
		int op1 = 1 + solve(i, j + 1, s1, s2, distance);	// add character 
		int op2 = 1 + solve(i + 1, j, s1, s2, distance); 	// remove character
		int op3 = 1 + solve(i + 1, j + 1, s1, s2, distance); 	// replace character
		distance[i][j] = min({op1, op2, op3});
	}
	
	return distance[i][j];
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	// distance[i][j];
	// edit distance between s1[i] and s2[j]
	vector<vector<int>> distance(s1.size(), vector<int> (s2.size(), -1));
	// top down memoization
	cout << solve(0, 0, s1, s2, distance);  

       	
	return 0;
}
