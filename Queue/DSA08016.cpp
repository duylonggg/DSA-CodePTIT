#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int l1[] = {0, 4, 1, 3, 8, 5, 2, 7, 9, 6};
int r1[] = {3, 0, 2, 7, 4, 1, 6, 8, 5, 9};
int l2[] = {1, 5, 2, 0, 4, 8, 6, 3, 7, 9};
int r2[] = {0, 2, 6, 3, 1, 5, 9, 7, 4, 8};

string Change(const string& str, int a[]) {
    string res = "";
    for (int i = 0; i < 10; ++i) 
        res += str[a[i]]; 
    return res;
}

int main() {
    fastio();
    tests() {
        unordered_map<string, int> vis;
        int ans = 1e9;
        string A, B = "1238004765"; 
        for (int i = 0; i < 10; ++i) {
            int x;
            cin >> x;
            A += to_string(x); 
        }

        queue<pair<string, int>> q1, q2;
        q1.push({A, 0}); 
        q2.push({B, 0});

        vis[A] = 0;
        vis[B] = 0;

        while (!q1.empty()) {
            auto [tmp, steps] = q1.front();
            q1.pop();

            string new_state = Change(tmp, l1); 
            if (!vis[new_state]) {
                vis[new_state] = steps + 1;
                q1.push({new_state, steps + 1});
            }

            new_state = Change(tmp, r1); 
            if (!vis[new_state]) {
                vis[new_state] = steps + 1;
                q1.push({new_state, steps + 1});
            }

            if (steps == 14) break;
        }

        while (!q2.empty()) {
            auto [tmp, steps] = q2.front();
            q2.pop();

            if (vis[tmp]) 
                ans = min(ans, vis[tmp] + steps);

            string new_state = Change(tmp, l2); 
            q2.push({new_state, steps + 1});

            new_state = Change(tmp, r2); 
            q2.push({new_state, steps + 1});

            if (steps == 14) break;
        }

        cout << ans << endl;
    }

    return 0;
}