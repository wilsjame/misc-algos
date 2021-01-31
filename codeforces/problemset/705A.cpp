#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++) {
        if (i == n) {
            n % 2 ? s += "I hate it" : s += "I love it";
        } 
        else if (i % 2) {
            s += "I hate that ";
        }
        else {
            s += "I love that ";
        }
    }
    cout << s;
    
    return 0;
}
