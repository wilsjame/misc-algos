#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n; 
    int max = 0, curr = 0;
    while (n--) {
        int out, in; 
        cin >> out >> in;
        curr += (in - out);
        if (curr > max) {
            max = curr;
        }
    }
    cout << max << endl;
    return 0;
}
