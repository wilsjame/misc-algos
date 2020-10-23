#include <iostream>
using namespace std;

#define ll long long

int main() {
	ll N, K, X, Y, t = 0;
	cin >> N >> K >> X >> Y;
	
	for (int i = 0; i < N; i++) {
		if (i < K)
			t += X;
		else
			t += Y;
	}
	cout << t;


	return 0;
}
