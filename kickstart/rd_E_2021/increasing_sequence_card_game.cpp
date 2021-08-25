#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

const int mxN = 10;
int n, total, A;
vector<int> permutation;
bool chosen[mxN + 1];

void search() {
    if (permutation.size() == n) {
        int cnt = 1;
        int cur = permutation[0];
        for (int i = 0; i < n - 1; i++) {
            if (permutation[i + 1] > cur) {
                cur = permutation[i + 1];
                cnt++;
            }
        }
        total += cnt;
        A++;
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}
int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cin >> n; 
        for (int i = 1; i <= n; i++) {
            chosen[i] = false;
        }
        permutation.clear();
        total = 0; // cards drawn 
        A = 0; // deck permutations 
        search();
        double En = (double) total / A;
        cout << "Case #" << tc << ": " << setprecision(15) << En << endl;
    }
    return 0;
}
