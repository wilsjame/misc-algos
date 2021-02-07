// TODO O(log(n))
#include <iostream>
#include <queue>
using namespace std;
const int N = 2 * (10000+5);
int visit[N];
int steps[N];

int main() {
    int n, m;
    cin >> n >> m;
    queue<int> q;
    q.push(n);
    visit[n] = 1;
    steps[n] = 0;

    // BFS
    while(!q.empty()) {
        int s = q.front();
        q.pop();
        // from nose s we can go to s - 1 or s * 2
        if (s > 0 && !visit[s - 1]) {
            visit[s - 1]  = 1;
            steps[s - 1] = steps[s] + 1;
            q.push(s - 1);
        }
        if (s <= m && !visit[2 * s]) {
            visit[2 * s] = 1;
            steps[2 * s] = steps[s] + 1;
            q.push(2 * s);
        }
    }
    cout << steps[m] << endl;

    return 0;
}
