/*
ID: jgwilso1
PROG: beads
LANG: C++                 
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);

    int n;
    string b;
    cin >> n;
    cin >> b;

    int seq_L;
    int seq_R;
    int color; 
    int k;
    int max = 0;

    b += b; // two copies to be able to runaround the ends
    for (int i = 0; i < b.length(); i++) {
        seq_L = 1;
        seq_R = 1;
        color = (b[i] == 'w') ? b[i-1] : b[i];
        for (k = 1; (i - k) > 0 && (b[i-k] == color || b[i-k] == 'w'); k++) { 
            seq_L++;
        }
        color = (b[i+1] == 'w') ? b[i+2] : b[i+1];
        for (k = 1; ((i +1) + k) < b.length() && (b[(i+1)+k] == color || b[(i+1)+k] == 'w'); k++) {
            seq_R++;
        }
        if (seq_L + seq_R > max) {
            max = seq_L + seq_R;
        }
    }
    // cap max at original number of beads because we made two copies
    if (max > n) {
        max = n;
    }
    cout << max << endl;

    return 0;
}
