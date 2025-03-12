#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXN = 100005;

int N;
ll BIT[MAXN], arr[MAXN];

void updateBIT(int i, ll x) {
    while (i <= N) {
        BIT[i] += x;
        i += i & -i;
    }
}

ll queryBIT(int i) {
    ll sum = 0;
    while (i > 0) {
        sum += BIT[i];
        i -= i & -i;
    }
    return sum;
}

ll getRangeBIT(int L, int R) {
    return queryBIT(R) - queryBIT(L - 1);
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        updateBIT(i, arr[i]);  
    }

    int Q;
    cin >> Q;
    while (Q--) {
        char type;
        cin >> type;
        if (type == 'q') {
            int L, R;
            cin >> L >> R;
            cout << getRangeBIT(L, R) << endl;
        } else {
            int i, x;
            cin >> i >> x;
            updateBIT(i, x - arr[i]); 
            arr[i] = x;
        }
    }
}
