#include <iostream>
using namespace std;
int main() {
    int n,m,z, ans = 0;
    scanf("%d %d %d",&n,&m,&z);
    for (int t=1;t<z+1;t++)
        ans += t%n==0 && t%m==0;
    cout << ans;
    return 0;
}
