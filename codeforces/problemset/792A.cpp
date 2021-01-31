#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &x : A) 
        cin >> x;
    sort(A.begin(), A.end());

    int total = 0, dist_min = 2e9 + 5;
    for (int i = 0; i + 1 < N; i++) {
        int dist;
        dist = abs(A[i + 1] - A[i]);
        if (dist < dist_min) {
            dist_min = dist;
            total = 1;
        }
        else if (dist == dist_min) {
            total++;
        }
    }
    cout << dist_min << " " << total << endl;

    return 0;
}
