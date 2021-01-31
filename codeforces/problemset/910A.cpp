#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    int n, d, j = 0;
    cin >> n >> d >> s;

    // greedy, always jump to furthest reachable lily pad
    for (int d_new = d, i = 0; i < n - 1;) {
        if (i + d >= n) {
            // jump
            j++;
            //home
            break;
        }
        else if (s[i + d] == '1') {
            // jump
            i = i + d;
            //cerr << "jump to " << i << " " << s[i] << endl;
            j++;
            d = d_new;
        }
        else if (--d == 0) {
            // no way home
            j = -1;
            break;
        }
    } 
    cout << j << endl;

    return 0;
}
