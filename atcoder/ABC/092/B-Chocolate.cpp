#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, D, X;
    cin >> N >> D >> X;
    vector<int> A(N);
    for (auto &v : A) cin >> v;

    int chocolates = N;
    for (int d : A) {
        for (int i = 1; 1 + (d * i) <= D; i++) {
            chocolates++;
        }
    }
    cout << chocolates + X << endl;

    return 0;
}
