#include <iostream>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;

    set<int> st;
    for (int i = 0; i < N; i++) {
        int d;
        cin >> d;
        st.insert(d);
    }

    cout << st.size() << endl;

    return 0;
}

