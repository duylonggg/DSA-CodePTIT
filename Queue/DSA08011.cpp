#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int n;
string S, T;

inline int BFS(unordered_set<string>& mySet) {
    mySet.erase(S);
    queue<pair<string, int>> q;
    q.push({S, 1});

    while (!q.empty()) {
        auto [str, steps] = q.front();
        q.pop();

        for (size_t j = 0; j < str.size(); ++j) {
            char ori = str[j];

            for (char c = 'A'; c <= 'Z'; ++c) {
                str[j] = c;
                if (str == T) return steps + 1;

                if (mySet.find(str) != mySet.end()) {
                    mySet.erase(str);  
                    q.push({str, steps + 1});
                }
            }
            str[j] = ori; 
        }
    }
    return -1;
}

int main() {
    fastio();
    tests() {
        cin >> n >> S >> T;
        unordered_set<string> mySet;

        while (n--) {
            string str;
            cin >> str;
            mySet.insert(str);
        }

        cout << BFS(mySet) << endl;
    }
    return 0;
}