#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int N, P, S;
vector<int> primes, numb;
vector<vector<int>> res;

void sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

void Try(size_t start, int total = 0) {
    if (total > S) return;
    
    if (total == S) {
        if (numb.size() == N) res.push_back(numb);
        return;
    }

    for (size_t i = start; i < primes.size(); ++i) {
        if (total + primes[i] > S) return;
        numb.push_back(primes[i]);
        Try(i + 1, total + primes[i]);
        numb.pop_back();
    }
}

int main() {
    sieve(200);

    tests() {
        cin >> N >> P >> S;
        res.clear();

        int start = upper_bound(primes.begin(), primes.end(), P) - primes.begin();

        Try(start);

        cout << res.size() << endl;
        for (auto vec : res) {
            for (auto num : vec) cout << num << ' ';
            cout << endl;
        }
    }
    return 0;
}