#include <iostream>
using namespace std;

int x[100], y[100];
bool visited[100];
int n;

void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
    // process node s
    // visit all connected points
    for (int i = 0; i < n; i++) 
        if (x[i] == x[s] || y[i] == y[s]) 
            dfs(i);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt - 1 << endl;

    return 0;
}
