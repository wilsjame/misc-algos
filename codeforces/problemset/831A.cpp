#include <iostream>
#include <vector>
using namespace std;

int main () {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &v : A)
        cin >> v;

    bool unimodal = true;
    int pos_1 = 0, pos_2 = N - 1;
    while (A[pos_1 + 1] > A[pos_1]) 
        pos_1++;
    while (A[pos_2 - 1] > A[pos_2])
        pos_2--;
    for (; pos_1 < pos_2; pos_1++)
        if (A[pos_1] != A[pos_2])
            unimodal = false;
    cout << (unimodal ? "YES\n" : "NO\n");

    return 0;
}
