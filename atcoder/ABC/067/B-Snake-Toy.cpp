#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K, ans = 0;
    cin >> N >> K;
    vector<int> A(N);
    for (auto &a : A)
        cin >> a;

    sort(A.rbegin(), A.rend());
    for (int i = 0; i < K; i++) 
        ans += A[i];

    cout << ans << endl;

    return 0;
}
