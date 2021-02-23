#include <iostream>
using namespace std;
#define MX 1005
int n,m,K,ans;
char g[MX][MX];
int vis[MX][MX];
int color[MX*MX];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

void dfs(int x, int y) {
    if (vis[x][y]) return;
    vis[x][y] = K;
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i];
        int b = y + dy[i];
        if (g[a][b] == '*') {
            ans++;
        }
        else if (g[a][b] == '.') {
            dfs(a,b);
        }
    }
    return;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    for (K = 1; K <= k; K++) {
        int x,y;
        cin >> x >> y;
        ans = 0;
        if (!vis[x][y]) {
            dfs(x,y);
            color[K] = ans;
        }
        ans = color[vis[x][y]];
        cout << ans << endl;
    }

    return 0;
}
