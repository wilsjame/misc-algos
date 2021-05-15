#include <iostream>
using namespace std;
int main() {
    int n; 
    cin >> n;
    char names[100][100] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    int cnt = 0;
    int p = 1;
    for (;;) {
        for (int i = 0; i < 5; i++) { 
            cnt += p;
            if (cnt >= n) {
                cout << names[i] << endl;
                return 0;
            }
        }
        p <<= 1;
    }
    return 0;
}
