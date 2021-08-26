#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int total, A;
const double EULER_MASCHERONI_CONST = 0.577215664901532;

void search(vector<int> a, int n, bool chosen[]) {
    if ((int)a.size() == n) {
        // process permutation
        int cnt = 1;
        int cur = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] > cur) {
                cur = a[i];
                cnt++;
            }
        }
        total += cnt;
        A++;
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (chosen[i]) continue;
            a.push_back(i);
            chosen[i] = true;
            search(a, n, chosen);
            a.pop_back();
            chosen[i] = false;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        long long n; 
        double Ev;
        cin >> n;
        if (n <= 10) {
            vector<int> a;
            total = 0, A = 0;
            bool chosen[n + 1] = {false};
            search(a, n, chosen);
            Ev = (double) total / A;
        }
        else if (n <= 1e6) {
            double dp[n + 1] = {};
            for (int i = 1; i <= n; i++) {
                dp[i] = (double) 1 / i + dp[i - 1];
            }
            Ev = dp[n];
        }
        else { // n <= 1e18
            // thx wiki ^_^ H(n) harmonic sum approx.
            Ev = log(n) + EULER_MASCHERONI_CONST;
        }
        cout << "Case #" << tc << ": " << setprecision(15) << Ev << endl;
    }
    return 0;
}

// Brute force O(n * n!), inspect output, and notice it is the harmonic sum!
// i.e. sum 1/n, n = 1, n -> x
// for large n we can add each term 1/n in O(n)
// for larger n we need a O(1) solution; use Euler-Mascheroni constant
