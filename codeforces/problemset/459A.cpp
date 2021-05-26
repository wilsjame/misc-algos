#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2) {
        cout << x1 + (y2 - y1) << " " << y1 << " " << x2 + (y2 - y1) << " " << y2 << endl;
    }
    else if (y1 == y2) {
        cout << x1 << " " << y1 + (x2 - x1) << " " << x2 << " " << y2 + (x2 - x1) << endl;
    }
    else if (abs(x2 - x1) == abs(y2 - y1)) {
        // quadrants I, II, III, IV
        if (x2 > x1 && y2 > y1) {
            x3 = x2;
            y3 = y1;
            x4 = x1;
            y4 = y2;
        }
        else if (x2 < x1 && y2 > y1) {
            x3 = x2;
            y3 = y1;
            x4 = x1;
            y4 = y2;
        }
        else if (x2 < x1 && y2 < y1) {
            x3 = x2;
            y3 = y1;
            x4 = x1;
            y4 = y2;
        }
        else if (x2 > x1 && y2 < y1) {
            x3 = x2;
            y3 = y1;
            x4 = x1;
            y4 = y2;
        }
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    }
    else {
        cout << -1 << endl;
    }
    
    return 0;
}
