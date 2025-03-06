#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio();
    tests() {
        int n, m, num;
        cin >> n >> m;

        unordered_set<int> uni;
        vector<int> union_res, inter_res;

        for (int i = 0; i < n; ++i) {
            cin >> num;
            if (uni.insert(num).second) union_res.push_back(num);
        }
        for (int i = 0; i < m; ++i) {
            cin >> num;
            if (!uni.insert(num).second) inter_res.push_back(num);
            else union_res.push_back(num);
        }

        sort(union_res.begin(), union_res.end());
        sort(inter_res.begin(), inter_res.end());

        for (int num : union_res) cout << num << ' ';
        cout << endl;
        for (int num : inter_res) cout << num << ' ';
        cout << endl;
    }
    return 0;
}
