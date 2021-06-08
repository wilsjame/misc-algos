#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int _25, _50, _100;
    _25 = 0;
    _50 = 0;
    _100 = 0;
    for(int i=0; i < n; i++) {
        int v;
        cin >> v;
        if (v == 25) {
            _25++;
        }
        if (v == 50) {
            if (_25 > 0) {
                _25--; 
            }
            else {
                cout << "NO" << endl;
                return 0;
            }
            _50++;
        }
        else if (v == 100) {
            if (_50 > 0 && _25 > 0) {
                _50--;
                _25--;
            }
            else if (_25 > 2) {
                _25 -= 3;
            }
            else {
                cout << "NO" << endl;
                return 0;
            }
            _100++;
        }
    }
    cout << "YES" << endl;
    return 0;
}
