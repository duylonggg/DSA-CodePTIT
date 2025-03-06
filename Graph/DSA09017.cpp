#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n;
        cin >> n;

        set<int> st;
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;

            st.insert(u);
            st.insert(v);
        }

        cout << (st.size() == n ? "YES" : "NO") << endl;
    }
    return 0;
}