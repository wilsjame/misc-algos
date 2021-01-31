#include <iostream>
using namespace std;
int main() {
    int x;
    cin >> x;
    cout << (x % 5 == 0 ? x / 5 : (x / 5) + 1);
    //cout << (x / 5) + 1 << endl;
    /*
    int s, r;
    s = x / 5;
    r = x % 5;
    for (int i = 4; r != 0; r %= i, i--) {
        s += r / i;
    }
    cout << s << endl;
    */
    
    return 0;
}
