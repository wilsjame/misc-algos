#include <iostream>
#include <string>
using namespace std;
int main() {
    string w;
    cin >> w;
    if (w[0] > 90) {
        //char c = w[0] - 32;
        w[0] = w[0] - 32;
    }
    cout << w << endl;
    return 0;
}
