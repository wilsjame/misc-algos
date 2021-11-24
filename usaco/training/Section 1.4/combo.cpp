/*
ID: jgwilso1
PROG: combo
LANG: C++                 
*/

#include <iostream>
#include <set>

using namespace std;

// Creates a set with the valid numbers 
// for one of the lock dial positions.
void buildset(int N, int n, set<int>& s) {
    int hi = n, low = n;
    s.insert(n);

    // low
    if (--low == 0) {
        low = N;
    }
    s.insert(low);
    if (--low == 0) {
        low = N;
    }
    s.insert(low);

    // hi
    if (++hi > N) {
        hi = 1;
    }
    s.insert(hi);
    if (++hi > N) {
        hi = 1;
    }
    s.insert(hi);
    
    return;
}

int main() {
    cerr << "___program start___\n";
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);

    int N, n, result = 0;
    set<int> pos1, pos2, pos3, m_pos1, m_pos2, m_pos3;

    // lock dial's max
    cin >> N;

    // farmer's combination
    cin >> n; buildset(N, n, pos1);
    cin >> n; buildset(N, n, pos2);
    cin >> n; buildset(N, n, pos3);

    // master combination
    cin >> n; buildset(N, n, m_pos1);
    cin >> n; buildset(N, n, m_pos2);
    cin >> n; buildset(N, n, m_pos3);

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            for (int k=1; k<=N; k++) {
                if ( (pos1.count(i) > 0 && pos2.count(j) > 0 && pos3.count(k) > 0) ||
                     (m_pos1.count(i) > 0 && m_pos2.count(j) > 0 && m_pos3.count(k) > 0) ) {
                    cerr << i << ", " << j << ", " << k << endl;
                    result++;
                }
            }
        }
    }

    cerr << result << endl;
    cout << result << endl;
    
    return 0;
}
