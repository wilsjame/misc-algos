#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

#define ll long long

int main() {
    ll N, K, ans;
    cin >> N >> K;

    vector<pair<int, int>> V;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        V.push_back({a, b});
    }
    
    sort(V.begin(), V.end());
    for (auto p : V) {
        K -= p.second;
        if (K <= 0) {
            ans =  p.first;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
