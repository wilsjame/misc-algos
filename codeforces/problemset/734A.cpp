#include <iostream>
using namespace std;
int main() {
    int n, a = 0, d = 0;
    char c;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        if (c == 'A') a++;
        else if (c == 'D') d++;
    }
    if (a > d) cout << "Anton" << endl;
    else if (d > a) cout << "Danik" << endl;
    else cout << "Friendship" << endl;
    return 0;
}
