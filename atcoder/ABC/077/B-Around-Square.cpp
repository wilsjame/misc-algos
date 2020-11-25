#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N, ans;
    cin >> N;

    ans = int(sqrt(N)) * int(sqrt(N)); 
    cout << ans << endl;

    return 0;
}
