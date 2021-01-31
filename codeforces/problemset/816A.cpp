#include <cstdio>
using namespace std;

int main() {
    int m, h;
    scanf("%d:%d", &h, &m);
    
    int t = 0;
    for(;;t++) {
        if ((h / 10 == m % 10) && (h % 10 == m / 10)) break;

        m++;
        if (m == 60) m = 0, h++;
        if (h == 24) h = 0;
    }
    printf("%d", t);

    return 0;
}
