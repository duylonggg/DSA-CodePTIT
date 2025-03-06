#include <bits/stdc++.h>
using namespace std;

size_t n, k;
vector<int> v, numb;

void print() {
    for (int i : numb) cout << i << ' ';
    cout << '\n';
}

void gen(int start) {
    if (numb.size() == k) {
        print();
        return;
    }
    
    for (size_t i = start; i < v.size(); ++i) {
        numb.push_back(v[i]);
        gen(i + 1);
        numb.pop_back();
    }
}

int main() {
    cin >> n >> k;
    set<int> st;

    while (n--) {
        int x;
        cin >> x;
        st.insert(x);
    }

    v.assign(st.begin(), st.end());
    gen(0);

    return 0;
}
