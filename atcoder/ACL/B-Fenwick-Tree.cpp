#include <iostream>
#include <vector>
using namespace std;

// sum from range [1, i] 1-based idx
long long sum(vector<long long>& tree, int i) {
    long long s = 0;
    while (i > 0) {
        s += tree[i];
        i -= i & -i;
    }
    return s;
}

// add x to the value at i 1-based idx
void add(vector<long long>& tree, int i, int x) {
    while (i < tree.size()){
        // propagate change 
        tree[i] += x;
        i += i & -i;
    }
}

int main() {
    int N, T;
    cin >> N >> T;
    vector<long long> A(N);
    for (auto &a : A) {
        cin >> a;
    }

    // make fenwick tree
    vector<long long> fenw = {0};
    fenw.insert(fenw.end(), A.begin(), A.end());
    for (int i = 1; i < fenw.size(); i++) {
        // update immediate parent
        int p = i + (i & -i);
        fenw[p] = fenw[i] + fenw[p];
    }

    while (T--) {
        int t, m, n;
        cin >> t >> m >> n;
        if (t == 0) {
            int i, x;
            i = m + 1, x = n;
            add(fenw, i, x);
        }
        else if (t == 1) {
            int l, r;
            l = m + 1, r = n;
            cout << sum(fenw, r) - sum(fenw, l-1) << endl;
        }
    }

    return 0;
}
