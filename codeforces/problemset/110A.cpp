#include <iostream>
#include <string>
using namespace std;
int main() {
    int count = 0;
    char c;
    while (cin.get(c)) {
        count += (c == '4' || c == '7'); 
    }
    cout << (count == 4 || count == 7 ? "YES" : "NO") << endl; 
    return 0;
}
