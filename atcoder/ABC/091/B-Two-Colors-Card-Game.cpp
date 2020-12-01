#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    unordered_map<string, int> hash_set;
    string s;
    int N, M, ans = 0;
    cin >> N;
    for (int i = 0; i < N; i++) { 
        cin >> s;
        hash_set[s]++;
    }
    cin >> M;
    for (int i = 0; i < M; i++) { 
        cin >> s;
        hash_set[s]--;
    }
    for (auto p : hash_set) {
        ans = max(ans, p.second);
    }
    cout << ans << endl;
    
    return 0;
}
