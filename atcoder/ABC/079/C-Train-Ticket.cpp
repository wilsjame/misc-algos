#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int A, B, C, D;
    scanf("%1d%1d%1d%1d", &A, &B, &C, &D);

    for (int op1 = 0; op1 < 2; op1++) {
        for (int op2 = 0; op2 < 2; op2++) {
            for (int op3 = 0; op3 < 2; op3++) {
                int res = 0;
                op1 == 1 ? res += A + B : res += A - B;
                op2 == 1 ? res += C : res -= C;
                op3 == 1 ? res += D : res -= D;
                if (res == 7) {
                    cout << A << (op1 == 1 ? "+" : "-") << B << (op2 == 1 ? "+" : "-") << C << (op3 == 1 ? "+" : "-") << D << "=7" << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
