#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;

#define ll long long

ll const INF = 1e10;

int main() {
    ll N, sum_l = 0, sum_r = 0, ans = INF;
    cin >> N;

    stack<ll> st;
    for (int i = 0; i < N; i++) {
        ll k;
        cin >> k;
        sum_l += k;
        st.push(k);
    }
    while (st.size() > 1) {
        sum_r += st.top(); 
        sum_l -= st.top();
        st.pop();
        ans = min(ans, abs(sum_l - sum_r));
    }

    cout << ans << endl;

    return 0;
}
