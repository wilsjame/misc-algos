#include <iostream>
#include <string>
using namespace std;
int cnt['Z' + 1];
int main() {
    string a, b, c;
    cin >> a >> b >> c;
    for (char x : a) {
        cnt[int(x)]++;
    }
    for (char x : b) {
        cnt[int(x)]++;
    }
    for (char x : c) {
        cnt[int(x)]--;
    }
    for (int i = 'A'; i <= 'Z'; i++) {
        if (cnt[i] != 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
