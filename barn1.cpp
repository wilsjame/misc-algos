/*
ID: jgwilso1
PROG: barn1
LANG: C++                 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int M, S, C, result; 
    vector<int> stalls, gaps;

    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);

    cin >> M >> S >> C;
    if (C == 1) { cout << 1 << endl; return 0; } 

    for (int n; cin >> n; stalls.push_back(n)) {}
    sort(stalls.begin(), stalls.end());

    for (int i = 0; i < C - 1; i++) {
        gaps.push_back(stalls[i + 1] - stalls[i]);
    }
    sort(gaps.rbegin(), gaps.rend()); // descending

    // one board covering all stalls
    result = stalls.back() - stalls.front() + 1;
    for (int i = 0; i < M - 1 && result != C; i++) {
        result -= gaps[i] - 1; // greedy
    }
    cout << result << endl;

    return 0;
}
