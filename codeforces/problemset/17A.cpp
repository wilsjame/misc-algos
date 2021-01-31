#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> a;
    int n, k;
    cin >> n >> k;
   
    for (int i = 2; i <= n; i++) {
        bool isPrime = true;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            a.push_back(i);
        }
    }

    for (int i = 0; i + 1 < a.size(); i++) {
        int sum = a[i] + a[i + 1];
        if (sum + 1 > n) {
            break;
        }
        else if (count(a.begin(), a.end(), sum + 1) > 0) {
            k--;
        }
    }

    if (k <= 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    
    return 0;
}

