#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) {
    return a.second > b.second;
}

int main() {
    int N, a, b;
    cin >> N;
    vector<pair<int, int>> A;
    vector<pair<int, int>> B;
    for (int i = 0 ; i < N; i++) {
        cin >> a >> b;
        A.push_back(make_pair(a, b));
    }
    for (int i = 0 ; i < N; i++) {
        cin >> a >> b;
        B.push_back(make_pair(a, b));
    }

    sort(B.begin(), B.end()); // x ascending
    sort(A.begin(), A.end(), sortbysec); // y descending

    int ans = 0;
    for (int i = 0; i < (int)B.size(); i++) {
        int bx, by;
        bx = B[i].first, by = B[i].second;
        for (int j = 0; j < (int)A.size(); j++) {
            int ax, ay;
            ax = A[j].first, ay = A[j].second;
            if (bx > ax && by > ay) {
                ans++;
                B.erase(B.begin() + i);
                A.erase(A.begin() + j);
                i = -1;
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
