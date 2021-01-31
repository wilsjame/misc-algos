#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int hrs = 0, used = 0;
    while (a > 0) {
        hrs += a;
        used += a; 
        a = 0;
        while (used >= b) {
            a++;
            used -= b;
        }
    }
    cout << hrs;

    return 0;
}
