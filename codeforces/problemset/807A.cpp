#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        A[i] = make_pair(a, b);
    }

    bool rated = false, maybe = true;
    for (int i = 0; i + 1 < N; i++) {
        int a1, a2, b1, b2;
        a1 = A[i].first;
        a2 = A[i].second;
        b1 = A[i + 1].first;
        b2 = A[i + 1].second;
        if (a1 != a2 || b1 != b2)
            rated = true;
        else if (b2 > a2)
            maybe = false;
    }
    if (rated)
        cout << "rated";
    else if (!rated && !maybe)
        cout << "unrated";
    else 
        cout << "maybe";

    return 0;
}
