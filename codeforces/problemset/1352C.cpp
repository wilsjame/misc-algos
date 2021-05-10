#include <iostream>
using namespace std;
#define ll long long
int main() {
    int t; 
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        ll lb, rb, mb;
        lb = 1, rb = 2 * k;
        while (lb < rb) {
            mb = (lb + rb) / 2;
            if (mb - mb / n >=  k) {
                rb = mb;
            }
            else {
                lb = mb + 1;
            }
        }
        cout << lb << endl;
    }
    return 0;
}
