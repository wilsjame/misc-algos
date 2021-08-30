#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
const int mxN = 300;
int g[mxN + 1][mxN + 1];
bool visited[mxN + 1][mxN + 1];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int r, c;
        cin >> r >> c;
        priority_queue<pair<int, pair<int, int>>> mx_heap;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> g[i][j];
                visited[i][j] = false;
                mx_heap.push({g[i][j], {i, j}}); 
            }
        }
        long long cnt = 0;
        while (!mx_heap.empty()) {
            auto u = mx_heap.top();
            int mx = u.first;
            int mxX = u.second.first;
            int mxY = u.second.second;
            if (!visited[mxX][mxY]) {
                // update neighbors
                for (int d = 0; d < 4; d++) {
                    int nI = mxX + dx[d];
                    int nJ = mxY + dy[d];
                    if ((nI < 0 || nJ < 0) || (nI > r - 1) || nJ > c - 1) {
                        continue;
                    }
                    if (mx - g[nI][nJ] > 1) {
                        cnt += mx - g[nI][nJ] - 1; 
                        g[nI][nJ] = mx - 1;
                        mx_heap.push({g[nI][nJ], {nI, nJ}});
                    }
                }
                visited[mxX][mxY] = true;
            }
            mx_heap.pop();
        }
        printf("Case #%d: %lld\n", tc, cnt);
    }
    return 0;
}

// see all numbers are reaching to the max number
// i.e. we never need to increase the max, only the numbers surrounding it
// brute force O((rc)^2) for the max and update its neighbors, for every num
// we can use a max heap (priority queue) to store the max nums and locations
// now we can single pass using our data strucutre to retrieve the max vals
// remember to push updated neighbors!
// one pass and priority queue add/remove: O(rc * log(rc))
