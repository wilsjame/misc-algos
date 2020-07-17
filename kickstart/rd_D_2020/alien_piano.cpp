#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t, c = 0;
    cin >> t;

    while (++c <= t) {
        int k, a;
        cin >> k;
        if (k <= 4) {
            for (int i = 0; i < k; i++) cin >> a; // unused
            cout << "Case #" << c << ": " << 0 << endl;  
            continue;
        }

        vector<int> v;
        for (int i = 0; i < k; i++) {
            cin >> a;
            v.push_back(a);
        }

        int hi_streak = 0, lo_streak = 0, res = 0;
        for (int i = 0; i + 1 < v.size(); i++) {
            if (v[i + 1] > v[i]) {
                hi_streak++; lo_streak = 0;
            }
            else if (v[i + 1] < v[i]) {
                lo_streak++; hi_streak = 0;
            }
            if (hi_streak == 4 || lo_streak == 4) {
                res++;
                hi_streak = 0; lo_streak = 0;
            }
        }
        cout << "Case #" << c << ": " << res << endl;  
    }
    return 0;
}
