#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N + 2, 0);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    // calculate total S
    // subtract two trips connected to skipped trip
    // add the trip bridging the skipped trip
    int S  = 0;
    for (int i = 0; i <= N; i++) {
        S += abs(A[i] - A[i + 1]);
    }
    for (int i = 1; i <= N; i++) {
        int Si = S;
        Si -= abs(A[i - 1] - A[i]) + abs(A[i] - A[i + 1]);
        Si += abs(A[i - 1] - A[i + 1]);
        cout << Si << endl;
    }

    return 0;
}
