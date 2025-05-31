#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define test   int testcase; cin >> testcase; while(testcase--)

void LocPhat(int n) {
    queue<string> locphat;
    locphat.push("6");
    locphat.push("8");
    vector<string> lp;

    while (locphat.front().size() <= n) {
        string tmp = locphat.front(); locphat.pop();

        lp.push_back(tmp);

        locphat.push(tmp + "6");
        locphat.push(tmp + "8");
    }

    reverse(lp.begin(), lp.end());
    for (string s : lp) cout << s << ' ';
    cout << endl;
}

int main() {
    fastio;
    test {
        int n;
        cin >> n;
        LocPhat(n);
    }
    return 0;
}