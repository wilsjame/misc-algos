#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, a = 0, b = 0;
    cin >> N;
    vector<int> A(N);
    for (auto &v : A) cin >> v;
    sort(A.rbegin(), A.rend());
    for (int i = 0; i < N; i++) {
        (i % 2 == 0 ? a += A[i] : b += A[i]);
    }
    cout << a - b << endl;

    return 0;
}
