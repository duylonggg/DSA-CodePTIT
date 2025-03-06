#include <bits/stdc++.h>
using namespace std;

char c;
string cur;
vector<int> vis(26, false);

bool is_valid(const string& cur) {
    for (size_t i = 1; i < cur.length() - 1; ++i) 
        if ((cur[i] == 'A' or cur[i] == 'E') and
            (cur[i - 1] != 'A' and cur[i - 1] != 'E' and cur[i + 1] != 'A' and cur[i + 1] != 'E')) 
            return false;
    return true;
}

void gen(int len) {
    if (len == c - 'A' + 1) {
        if (is_valid(cur)) cout << cur << endl;
        return;
    }

    for (char i = 'A'; i <= c; ++i) {
        if (vis[i - 'A']) continue;

        vis[i - 'A'] = 1;
        cur.push_back(i);
        gen(len + 1);
        cur.pop_back();
        vis[i - 'A'] = 0;
    }
}

int main() {
    cin >> c;
    gen(0);
    return 0;
}