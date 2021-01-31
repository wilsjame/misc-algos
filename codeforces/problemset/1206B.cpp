#include <iostream>
using namespace std;
int main () {
    long long n, ans = 0;
    cin >> n;
    int a[n];

    int neg = 0, pos = 0, zer = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0){
            zer++;
        }
        else if (a[i] < 0) {
            neg++;
            //cerr << a[i] << endl;
            //cerr << "to -1 " << (a[i] * -1) - 1 << endl;;
            ans += (a[i] * -1) - 1;
        }
        else if (a[i] > 0) {
            pos++;
            //cerr << a[i] << endl;
            //cerr << "to 1 " << a[i] - 1 << endl;
            ans += a[i] - 1;
        }
    }
    if (zer == 0) {
        if (neg % 2 != 0) {
            ans += 2;
        }
    }
    else {
        ans += zer;
    }
    //cerr << "zer " << zer << endl << "pos " << pos << endl << "neg " << neg << endl;
    cout << ans << endl;

    return 0;
}
