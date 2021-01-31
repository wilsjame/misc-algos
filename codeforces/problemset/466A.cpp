#include <iostream>
using namespace std;
int main() {
    int target, m, a, b;
    cin >> target >> m >> a >> b;

    // greedy
    // singles are better
    if (a*m <= b) {
        cout << a * target;
    }
    else {
        int c = 0;
        // multis are better
        while (target - m >= 0) {
            target -= m;
            c += b;
        }
        // okay to have extra rides so,
        // determine if buying single tickets is
        // better than buying one more multi-ticket
        if (a * target <= b) {
            while (--target >= 0) {
                c += a;
            }
        }
        else { // buy a multi-ticket and have some rides leftover
            c += b;
        }
        cout << c;
    }

    return 0;
}
