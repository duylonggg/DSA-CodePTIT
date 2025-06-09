#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define test   int testcase; cin >> testcase; while(testcase--)

int main() {
    fastio;
    test {
        string str, word;
        getline(cin >> ws, str);
        stringstream ss(str);
        while (ss >> word) {
            reverse(word.begin(), word.end());
            cout << word << ' ';
        }
        cout << endl;
    }
    return 0;
}