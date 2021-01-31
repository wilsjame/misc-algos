#include <iostream>
using namespace std;

int main() {
    int k, r, n = 1;
    cin >> k >> r;
    /*
    if (r % k == 0) cout << r / k << endl; 
    else if (k % 10 == 0) cout << 1 << endl;
    */
    while ((n * k) % 10 != r && (n * k) % 10 != 0) {n++;}
    cout << n << endl;
    return 0;
}
