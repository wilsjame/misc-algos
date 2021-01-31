#include <iostream>
using namespace std;
int main() {
    int n, res = 0;; 
    cin >> n;
    while(n--) {
        int f1, f2, f3;
        cin >> f1 >> f2 >> f3;
        if (f1 + f2 + f3 > 1) {
            res++;
        }
    }
    cout << res << endl;

    return 0;
}
