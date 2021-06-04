#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int t; 
    cin >> t;
    while(t--) {
        cout << endl;
        int n, m;
        cin >> n >> m;
        vector<int> row(n, 0);
        vector<int> col(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int claim;
                cin >> claim;
                if (row[i] == 0 && claim == 1) {
                    row[i] = claim;
                }
                if (col[j] == 0 && claim == 1) {
                    col[j] = claim;
                }
            }
        }

        int turn = 0;
        while(count(row.begin(), row.end(), 0) > 0 && count(col.begin(), col.end(), 0) > 0) {
            int next = false;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (row[i] == 0 && col[j] == 0) {
                        row[i] = 1;
                        col[j] = 1;
                        turn++;
                        next = true;
                        break;
                    }
                }
                if (next)
                    continue;
            }
        }
        cout << (turn % 2 ? "Ashish" : "Vivek") << endl;
    }
    return 0;
}
