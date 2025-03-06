#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<string> names, name;
set<string> unique_name;

void gen(int start = 0) {
    if (name.size() == k) {
        for (string str : name) cout << str << ' ';
        cout << endl;
        return;
    }

    for (size_t i = start; i < names.size(); ++i) {
        name.push_back(names[i]);
        gen(i + 1);
        name.pop_back();
    }
}

int main() {
    cin >> n >> k;

    while (n--) {
        string name;
        cin >> name;
        unique_name.insert(name);
    }

    names.assign(unique_name.begin(), unique_name.end());

    gen();

    return 0;
}