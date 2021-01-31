#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (auto &x : a) cin >> x;
    
    long long steps = 0;
    for (int pos = 1, i = 0; i < m; i++) {
        int next = a[i];
        if (next > pos) 
            steps += next - pos;
        else if (next < pos) 
            steps += n - pos + next;
        pos = a[i];
    }
    cout << steps;

    return 0;
}

