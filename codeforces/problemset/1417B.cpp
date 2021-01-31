#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, T;
        cin >> n >> T;
        vector<int> a(n);
        for (auto &k : a) cin >> k;
        // seperate into three groups
        // 1) < T/2 
        // 2) == T/2
        // 3) > T/2
        // now put all of 1) and 3) in their own sets
        // because we know the sum of any pair of these 
        // elements will not equal T.
        // finally, evenly distribute the 2) group between
        // the sets of 1) and 2).
        // time: O(n) 
        // space: O(n)
        // watch out for T / 2 when T is odd!  
        vector<int> v(n);
        for (int alternate = 0, i = 0; i < n; i++) {
            if (T % 2 == 0 && T / 2  == a[i]) {
                v[i] = (alternate++) % 2;
            }
            else if (a[i] < T / 2) {
                v[i] = 0;
            }
            else if (a[i] > T / 2) {
                v[i] = 1;
            }
        }
        for (auto x : v) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
