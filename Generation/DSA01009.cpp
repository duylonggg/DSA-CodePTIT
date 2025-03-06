#include <bits/stdc++.h>
using namespace std;

int n, k, cnt;
vector<string> res;

bool check(const string& str) {
    int cnt = 0, seg = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'A') {
            ++cnt;
            if (cnt > k) return false;
            if (cnt == k) ++ seg;
        }
        else 
            cnt = 0;
    }
    return seg == 1;
}

void Try(string str = "") {
    if (str.size() == n) {
        if (check(str)) {
            ++cnt;
            res.push_back(str);    
        }
        return;
    }
    
    Try(str + "A");
    Try(str + "B");
}

int main() {
    cin >> n >> k;

    Try();

    cout << cnt << endl;
    for (string str : res) cout << str << endl;

    return 0;
}