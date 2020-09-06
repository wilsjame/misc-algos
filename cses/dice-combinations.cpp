#include <iostream>
using namespace std;

// recursive
/*
cnt = 0;
void solve(int x) {
    if (x < 0) return;
    if (x == 0) {
        cnt++;
        return;
    }
    for (int roll : {1, 2, 3, 4, 5, 6}) {
        solve(x - roll);
    }
}
*/

int main() {
    int n, m = 1e9 + 7, count[1000000 + 5] = {0};
    cin >> n;

    count[0] = 1;
    for (int x = 1; x <= n; x++) {
        for (int roll : {1, 2, 3, 4, 5, 6}) {
            if (x - roll >= 0) {
                count[x] += count[x - roll];
                count[x] %= m;
            }
        }
    }
    cout << count[n] << endl;

	return 0;
}
