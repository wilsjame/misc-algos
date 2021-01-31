#include <iostream>
#include <string>
using namespace std;
int main() {
    int l, res = 0;
    char c;
    cin >> l;
    if (l == 0) {
        cout << 0 << endl;
        return 0;
    }

    char curr, next;
    cin.get(curr);
    for (int i = 1; i <= l; i++) {
        cin.get(next);
        if (next == curr) {
            res++;
        }
        else {
            curr = next;
        }
    }
    cout << res << endl;

    return 0;
}
