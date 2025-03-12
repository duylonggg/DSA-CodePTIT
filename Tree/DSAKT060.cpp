#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;
const int BASE = 31;
const int MAXN = 100005;

int N, Q;
string S;
ll powBase[MAXN], BIT_F[MAXN], BIT_B[MAXN];

void precompute() {
    powBase[0] = 1;
    for (int i = 1; i < MAXN; ++i)
        powBase[i] = (powBase[i - 1] * BASE) % MOD;
}

void updateBIT(ll BIT[], int i, ll val) {
    while (i <= N) {
        BIT[i] = (BIT[i] + val) % MOD;
        i += i & -i;
    }
}

ll queryBIT(ll BIT[], int i) {
    ll sum = 0;
    while (i > 0) {
        sum = (sum + BIT[i]) % MOD;
        i -= i & -i;
    }
    return sum;
}

ll getRangeBIT(ll BIT[], int L, int R) {
    return (queryBIT(BIT, R) - queryBIT(BIT, L - 1) + MOD) % MOD;
}

void buildBIT() {
    memset(BIT_F, 0, sizeof(BIT_F));
    memset(BIT_B, 0, sizeof(BIT_B));

    for (int i = 1; i <= N; i++) {
        updateBIT(BIT_F, i, (S[i - 1] - '0' + 1) * powBase[i] % MOD);
        updateBIT(BIT_B, i, (S[i - 1] - '0' + 1) * powBase[N - i + 1] % MOD);
    }
}

void update(int U, char x) {
    ll old_val = (S[U - 1] - '0' + 1) * powBase[U] % MOD;
    ll new_val = (x - '0' + 1) * powBase[U] % MOD;
    updateBIT(BIT_F, U, (new_val - old_val + MOD) % MOD);

    old_val = (S[U - 1] - '0' + 1) * powBase[N - U + 1] % MOD;
    new_val = (x - '0' + 1) * powBase[N - U + 1] % MOD;
    updateBIT(BIT_B, U, (new_val - old_val + MOD) % MOD);

    S[U - 1] = x;  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S >> Q;
    N = S.size();

    precompute();
    buildBIT();

    while (Q--) {
        char type;
        cin >> type;
        if (type == 'q') {
            int L, R;
            cin >> L >> R;
            ll hashF = getRangeBIT(BIT_F, L, R) * powBase[N - R] % MOD;
            ll hashB = getRangeBIT(BIT_B, L, R) * powBase[L - 1] % MOD;
            if (hashF == hashB)
                cout << "YES\n";
            else
                cout << "NO\n";
        } else {
            int U;
            char x;
            cin >> U >> x;
            update(U, x);
        }
    }
    return 0;
}
