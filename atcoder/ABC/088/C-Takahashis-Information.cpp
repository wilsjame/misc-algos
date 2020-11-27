#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> C(3, vector<int>(3));
    for (auto &row: C) 
        for (auto &a : row)
            cin >> a;
    
    // A are constants, cycle through all choices for a1-3 and calculate b1-3
    // a1 + b1 = A1,1
    // a1 + b2 = A1,2 
    // a1 + b3 = A1,3
    // a2 + b1 = A2,1
    // a2 + b2 = A2,2
    // a2 + b3 = A2,3
    // a3 + b1 = A3,1
    // a3 + b2 = A3,2
    // a3 + b3 = A3,3
    int a[3], b[3];
    for (a[0] = 0; a[0] <= 100; a[0]++) {
        for (a[1] = 0; a[1] <= 100; a[1]++) {
            for (a[2] = 0; a[2] <= 100; a[2]++) {
                b[0] = C[0][0] - a[0];
                b[1] = C[0][1] - a[0];
                b[2] = C[0][2] - a[0];

                bool ok = true;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (a[i] + b[j] != C[i][j]) {
                            ok = false;
                        }
                    }
                }
                if (ok) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
