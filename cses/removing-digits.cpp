#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9 + 5;
int main() {
    int n;
    cin >> n;

    // recursive thinking (top down)
    // subtract every digit creating a tree all the way down
    // keep on subtracting every digit until zero is reached.
    // choose shortest path to zero

    // bottom up
    // 1 <= x <= n (target)
    // steps[x] is the minimum steps required to make x equal to zero
    vector<int> steps(n + 1);
    // base cases: 
    steps[0] = 0;
    for (int i = 1; i <= 9; i++) 
        steps[i] = 1;

    for (int x = 10; x <= n; x++) {
        steps[x] = INF;
        for (int digit : /* in n */) {
            if (x - digit >= 0) {
                steps[x] = min(steps[x], step[x - digit] + 1);
            }
        }
    }
    cout << steps[n];

    return 0;
}
