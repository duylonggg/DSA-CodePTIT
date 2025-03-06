#include <bits/stdc++.h>
using namespace std;

int n, k;
set<string> st;
vector<string> v, name;

void gen(int start = 0) {
    if (name.size() == k) {
        for (string str : name) cout << str << ' ';
        cout << endl;
        return;
    }

    for (size_t i = start; i < v.size(); ++i) {
        name.push_back(v[i]);
        gen(i + 1);
        name.pop_back();
    }
}

int main() {
    cin >> n >> k;

    while (n--) {
        string str;
        cin >> str;
        st.insert(str);
    }

    v.assign(st.begin(), st.end());

    gen();

    return 0;
}