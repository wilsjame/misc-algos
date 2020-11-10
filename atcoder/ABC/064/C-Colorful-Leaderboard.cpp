#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main() {
    int N, k;
    cin >> N;
    map<string, int> color; 
    for (int i = 0; i < N; i++) {
        cin >> k;
        if (k < 400)
            color["gray"]++;
        else if (k < 800)
            color["brown"]++;
        else if (k < 1200) 
            color["green"]++;
        else if (k < 1600)
            color["cyan"]++;
        else if (k < 2000) 
            color["blue"]++;
        else if (k < 2400)
            color["yellow"]++;
        else if (k < 2800)
            color["orange"]++;
        else if (k < 3200) 
            color["red"]++;
        else
            color["wild"]++;
    }

    int ans_min = 0, ans_max = 0, size, wild;
    size = color.size();
    wild = color["wild"];
    if (size == 1 && wild > 0) {
        ans_min = 1;
        ans_max = wild;
    }
    else { 
        ans_min = size - int(wild > 0);
        ans_max = ans_min + wild; 
    }
    cout << ans_min << " " << ans_max << endl;

    return 0;
}

