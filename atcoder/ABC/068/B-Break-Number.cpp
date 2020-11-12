#include <iostream> 
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int k = 1;
    while (k <= N)
        k *= 2;
    k /= 2;
    cout << k << endl;

    return 0;
}
