#include <iostream>
#include <vector>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	vector<int> child(N);
	vector<int> A(K); // steps for ith leader
	for (int i = 0; i < N; i++) 
		child[i] = i + 1;
	for (auto &x : A) 
		cin >> x;

	int pos = 0;
	for (auto step : A) {
		pos = (pos + step) % (int)child.size();
		cout << child[pos] << " ";
		child.erase(child.begin() + pos);
	}

	return 0;
}

