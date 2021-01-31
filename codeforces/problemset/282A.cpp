#include <iostream>
#include <string>
using namespace std;
int main() {
    int t, res = 0;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;

        if (s.find("++") != string::npos) {
            res++;
        }
        else {
            res--;
        }

    }
    cout << res << endl;
    return 0;
}
