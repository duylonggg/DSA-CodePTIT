#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v, seq;
vector<string> res;

void gen(int start) {
    if (seq.size() > 1) {
        string s;
        for (int num : seq) s += to_string(num) + " ";
        res.push_back(s);
    }

    for (int i = start; i < n; ++i) {
        if (!seq.empty() && seq.back() > v[i]) continue;
        seq.push_back(v[i]);
        gen(i + 1);
        seq.pop_back();
    }
}

int main() {
    cin >> n;
    v.resize(n);
    for (int &i : v) cin >> i;

    gen(0);

    sort(res.begin(), res.end());
    for (const string &s : res) cout << s << endl;

    return 0;
}
