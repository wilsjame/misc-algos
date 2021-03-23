#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct seg {
    int l, r, id;
};

bool cmp(seg a, seg b) {
    return a.l < b.l;
}

int sum(vector<int>& fenw, int i) {
    int s = 0;
    while (i > 0) {
        s += fenw[i];
        i -= i & -i;
    }
    return s;
}

void add(vector<int>& fenw, int i, int val) {
    while (i < fenw.size()) {
        fenw[i] += val;
        i += i & -i; 
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> ans(n);
    vector<seg> a(n);
    map<int, int> m;

    // store segments in a
    for (int i = 0; i < n; i++) {
        cin >> a[i].l;
        cin >> a[i].r;
        a[i].id = i;
        m[a[i].l] = 1;
        m[a[i].r] = 1;
    }
    
    // index compression (map is ordered ^_^) 
    int j = 1;
    for (auto &k : m) {
        k.second = j;
        j++;
    }

    // make fenwick tree
    vector<int> fenw(2 * n + 1, 0);
    for (int i = 0; i < n; i++) {
        fenw[m[a[i].r]]++;
    }
    for (int i = 0; i < fenw.size(); i++) {
        int p = i + (i & -i);
        if (p < fenw.size()) {
            fenw[p] = fenw[p] + fenw[i];
        }
    }
    
    // count segments to the right, below, and
    // within the range of the current segment
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < n; i++) {
        int l, r;
        l = m[a[i].l];
        r = m[a[i].r];
        ans[a[i].id] = sum(fenw, r) - sum(fenw, l - 1);
        // do not count this segment
        ans[a[i].id]--;
        // this segment hereafter is above so remove it
        add(fenw, r, -1);
    }

    for (auto k : ans) {
        cout << k << endl;
    }

    return 0;
}
