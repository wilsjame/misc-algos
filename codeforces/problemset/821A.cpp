#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int> (N));
    for (auto &row: A)
        for (auto &a : row)
            cin >> a;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] != 1) {
                bool good = false;
                // row values
                for (int s = 0; s < N; s++) {
                    if (s == j) continue;
                    int rv = A[i][s];
                        // col values
                        for (int t = 0; t < N; t++) {
                            if (t == i) continue;
                            int cv = A[t][j];
                            if (rv + cv == A[i][j])
                                good = true;
                        }
                }
                if (!good) {
                    cout << "No\n";
                    return 0;
                }
            }
        }
    }
    cout << "Yes\n";

    return 0;
}
