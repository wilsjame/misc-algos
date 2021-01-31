#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, k, ans, cnt = 0;
    cin >> n >> k;
    vector<int> a(n);

    // O(n)
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] + k <= 5) {
           cnt++; 
        }
    }

    ans = cnt / 3;
    cout << ans << endl;

    /*
    O(nlogn) + O(n)

    sort(a.begin(), a.end());
    if (n >= 3) {
        for (int i = 2; i < n; i += 3) {
            if (a[i] + k <=  5  ) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    */

    return 0;
}
