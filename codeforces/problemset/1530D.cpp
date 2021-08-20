#include <iostream>
#include <set>
using namespace std;
const int Mx = 2e5;
int a[Mx + 1], b[Mx + 1];
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        set<int> gift;
        for (int i = 1; i <= n; i++) {
            gift.insert(i);
            b[i] = 0; // no gift, yet! 
        }
        // greedy match first pass
        for (int i = 1; i <= n; i++) {
            if (b[i] == 0 && gift.count(a[i])) {
                gift.erase(a[i]);
                b[i] = a[i];
            }
        }
        // greedy match remaining
        for (int i = 1; i <= n; i++) {
            if (b[i] == 0) {
                auto canidate = *(gift.begin());
                if (i != canidate) {
                    b[i] = canidate;
                    gift.erase(canidate);
                }
            }
        }
        // assign remaining gifts, handle self matches
        for (int i = 1; i <= n && gift.size(); i++) {
            if (b[i] == 0) {
                if (i != *(gift.begin())) {
                    b[i] = *(gift.begin());
                    gift.erase(*(gift.begin()));
                }
                else if (i == *(gift.begin())) {
                    if (gift.size() > 1) {
                        b[i] = *(gift.end());
                        gift.erase(*(gift.end()));
                    }
                    else if (gift.size() == 1) {
                        b[i] = a[i];
                        // use look up here if TLE (passed! ^_^)
                        for (int j = 1; j <= n; j++) {
                            if (b[j] == a[i] && j != i) {
                                b[j] = i;
                            }
                        }
                    }
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += b[i] == a[i];
        }
        cout << cnt << endl;
        for (int i = 1; i <= n; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
