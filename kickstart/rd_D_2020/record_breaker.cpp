#include <iostream>
using namespace std;
int main() {
    int t, c = 0;
    cin >> t;

    while (++c <= t) {
        int n, curr, res = 0;
        cin >> n; cin >> curr;

        if (n == 1) {
            cout << "Case #" << c << ": " << 1 << endl;  
            continue;
        }

        for (int max = curr, next, i = 1; i <= n; i++) {
            bool first_day, last_day;
            i == 1 ? first_day = true : first_day = false;
            i == n ? last_day = true : last_day = false;  

            if (!last_day) cin >> next;
            if (first_day && (curr > next)) {
                res++;
                continue;
            }
            if (curr > max && (curr > next || last_day)) {
                res++;
                max = curr;
            }
            curr = next;
        }

        cout << "Case #" << c << ": " << res << endl;  
    }

    return 0;
}
