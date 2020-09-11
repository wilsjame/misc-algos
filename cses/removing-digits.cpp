#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e9 + 5;
int main() {
    int n;
    cin >> n;

    // steps[x] is the minimum steps required to make x equal to zero
    vector<int> steps(n + 1);
    // base cases 
    steps[0] = 0;
    for (int i = 1; i <= 9; i++) 
        steps[i] = 1;

    for (int x = 10; x <= n; x++) {
        steps[x] = INF;
        // for each digit in x
        int k = x;
        for (int digit = k % 10; k > 0; k /= 10, digit = k % 10) {
            if (x - digit >= 0) {
                steps[x] = min(steps[x], steps[x - digit] + 1);
            }
        }
    }
    cout << steps[n];

    return 0;
}
