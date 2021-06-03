#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> const_cnt(105, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            const_cnt[a[i]]++;
        }
        // brute force all sums
        // two sum variation
        int ans = 0;
        for (int s = 2; s <= 2 * n; s++) {
            int pairs = 0;
            vector<int> cnt = const_cnt;
            for (int i = 0; i < n; i++) {
                int need = s - a[i];
                if (need > 0 && (cnt[a[i]] > 0 && cnt[need] > 0)) {
                    if (cnt[need] == 1 && need == a[i]) 
                        continue;
                    pairs++;
                    cnt[a[i]]--;
                    cnt[need]--;
                }
            }
            ans = max(ans, pairs);
        }
        cout << ans << endl;
    }
    return 0;
}   
