#include <iostream>
#include <vector>
using namespace std;

const int N = 1e4 + 5;
vector<int> adj[N];
int color[N];
int color_new[N];
int cnt;

// current node s and previous node e
void dfs(int s, int e, int c) {
	// process node s
	color_new[s] = c;
	for (auto u : adj[s]) {
		if (u != e) dfs(u, s, c); 
	}
}

int main() {
	int n;
	cin >> n;
	for (int k, i = 2; i <= n; i++) {
		cin >> k;
		adj[k].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		cin >> color[i];
	}

	// dfs color each node starting from the top
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (color_new[i] != color[i]) {
			dfs(i, 0, color[i]);
			cnt++;
		}
	}
	cout << cnt << endl;

	return 0;
} 
