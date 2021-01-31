#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &v : a) cin >> v;

        int cnt_0 = 0, cnt_1 = 0;
        for (auto k : a) {
            if (k == 0)
                cnt_0++;
            else
                cnt_1++;
        }
        // we can remove at most n/2 elements
        // so if we have half or more zeros
        // print all zeros
        if (cnt_0 >= n / 2) {
            cout << n / 2 << endl;
            for (int i = 0; i < n / 2; i++) {
                cout << 0 << " ";
            }
        }
        // otherwise we have atleast n/2 ones
        else {
            // we need to print an even number of ones
            if (cnt_1 % 2 == 0) {
                cout << cnt_1 << endl;
                for (int i = 0; i < cnt_1; i++) {
                    cout << 1 << " ";
                }
            }
            else {
                cout << cnt_1 - 1 << endl;
                for (int i = 0; i < cnt_1 - 1; i++) {
                    cout << 1 << " ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}
