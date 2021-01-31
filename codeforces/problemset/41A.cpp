#include <iostream>
#include <string>
using namespace std;
int main() {
    string a;
    cin >> a;

    char b;
    for (int i = a.size() - 1; i >=0; --i) {
        cin >> b;
        if (b != a[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}
