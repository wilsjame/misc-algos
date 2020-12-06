#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, D, X;
    cin >> N >> D >> X;
    vector<int> A(N);
    for (auto &v : A) cin >> v;

    int chocolates = 0;
    for (int i = 0; i < N; i++) {
        chocolates += 1 + ((D - 1) / A[i]);
    }
    cout << chocolates + X << endl;

    return 0;
}
