#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        vector<bool> visited(N, false);
        vector<pair<int,int>> sol;
        for (auto& a : A) 
            cin >> a;

        for (int i = 0; i + 1 < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if ((!visited[i] || !visited[j]) && (A[j] != A[i])) {
                    visited[i] = visited[j] = true;
                    sol.push_back(make_pair(i + 1, j + 1));
                }
            }
        }
        if (sol.empty()) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            for (auto p : sol)
                cout << p.first << " " << p.second << endl;
        }
    }

    return 0;
}
