#include <iostream>
using namespace std;

#define ll long long

int main() {
    ll N, mod = 1000000000 + 7;
    cin >> N;

    ll ans = 1;
    for (int i = 0; i < N; i++) 
        ans = (ans * 2) % mod;
    cout << ans;
    
    return 0;
}
