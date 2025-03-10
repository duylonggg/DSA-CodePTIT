#include <bits/stdc++.h>
using namespace std;

struct Item {
    double weight, value;
};

bool cmp(Item a, Item b) {
    return (a.value / a.weight) > (b.value / b.weight);
}

void solve() {
    int N, W;
    cin >> N >> W;

    vector<Item> items(N);
    for (int i = 0; i < N; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    sort(items.begin(), items.end(), cmp);

    double maxValue = 0.0;
    for (auto item : items) {
        if (W >= item.weight) { 
            maxValue += item.value;
            W -= item.weight;
        } else { 
            maxValue += (item.value / item.weight) * W;
            break; 
        }
    }

    cout << fixed << setprecision(2) << maxValue << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
