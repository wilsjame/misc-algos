#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
    int N, T;
    cin >> N >> T;
    vector<int> A(N);
    for (auto &v : A)
        cin >> v;

    ll ans = 0;
    for (int i = 1; i < N; i++) 
        ans += min(A[i] - A[i - 1], T);
    cout << ans + T << endl;

    return 0;
}
