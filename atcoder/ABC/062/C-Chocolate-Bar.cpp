#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

const ll INF = 1e9 + 5;

int main() {
    ll H, W;
    cin >> H >> W;

    ll s1, s2, s3, ans = INF;

    // two cases
    // ---   ---
    // ---    |
    // --- ,  |
    for (int h = 1; h < H; h++) {
        s1 = h * W;
        s2 = ((H - h) / 2) * W; 
        s3 = (((H - h) / 2) + ((H - h) % 2 != 0)) * W;
        ans = min(ans, max({s1, s2, s3}) - min({s1, s2, s3}));
        s2 = (H - h) * (W / 2);
        s3 = (H - h) * ((W / 2) + (W % 2 != 0));
        ans = min(ans, max({s1, s2, s3}) - min({s1, s2, s3}));
    }

    // swap H and W, two cases again
    // | | |   |
    // | | |   |--
    // | | | , |
    ll temp = H;
    H = W;
    W = temp;
    for (int h = 1; h < H; h++) {
        s1 = h * W;
        s2 = ((H - h) / 2) * W; 
        s3 = (((H - h) / 2) + ((H - h) % 2 != 0)) * W;
        ans = min(ans, max({s1, s2, s3}) - min({s1, s2, s3}));
        s2 = (H - h) * (W / 2);
        s3 = (H - h) * ((W / 2) + (W % 2 != 0));
        ans = min(ans, max({s1, s2, s3}) - min({s1, s2, s3}));
    }

    cout << ans << endl;

    return 0;
}
