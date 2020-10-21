#include <iostream>
using namespace std;

#define ll long long

int main () {
    ll N;
    cin >> N;

    ll ans = 0;
    // factors of 5 method
    for (int k = 5; k <= N; k *= 5) 
        ans += N / k;
    cout << ans;

    return 0;
}
