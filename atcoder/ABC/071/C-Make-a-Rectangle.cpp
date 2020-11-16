#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), ans;
    for (auto &k : A)
        cin >> k;

    sort(A.rbegin(), A.rend());

    for (int i = 0; i + 1 < N && ans.size() < 4; i++) {
        if (A[i] == A[i + 1]) {
            ans.push_back(A[i]);
            ans.push_back(A[i + 1]);
            i++;
        }
    }

    cout << (ans.size() == 4 ? ans[0] * ans[2] : 0) << endl;

    return 0;
}
