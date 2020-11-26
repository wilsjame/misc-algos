#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(2, vector<int>(N));
    for (auto &row : A) {
        for (auto &a : row) {
            cin >> a;
        }
    }

    int ans = 0;
    for (int r = 0; r < N; r++) {
        int sum = 0;
        for (int i = 0; i <= r; i++) {
            sum += A[0][i];
        }
        for (int j = r; j < N; j++) {
            sum += A[1][j];
        }
        ans = max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}
