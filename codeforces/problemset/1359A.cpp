#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, k, ans;
        cin >> n >> m >> k;
        int h = n / k;
        if (m <= h) {
            ans = m;
        }
        else {
            vector<int> rem(k - 1, 0);
            for (int i = 0; i < m - h; i++) {
                rem[i % rem.size()]++;
            }
            if (*max_element(rem.begin(), rem.end()) == h) {
                ans = 0;
            }
            else {
                ans = h - *max_element(rem.begin(), rem.end()); 
            }
        }
        cout << ans << endl;
    }
    return 0;
}
