#include <bits/stdc++.h>
using namespace std;

#define tests() int test_cases; cin >> test_cases; while (test_cases--)

int n, k, sum;
vector<int> numb, subset;
vector<bool> visited;

bool Try(int idx) {
    if (idx == k) return true; 
    if (subset[idx] == sum / k) return Try(idx + 1); 

    for (int i = 0; i < n; ++i) {
        if (visited[i] || subset[idx] + numb[i] > sum / k) continue;

        visited[i] = true;
        subset[idx] += numb[i];

        if (Try(idx)) return true;

        visited[i] = false;
        subset[idx] -= numb[i];

        if (subset[idx] == 0) return false;
    }
    return false;
}

int main() {
    tests() {
        cin >> n >> k;

        sum = 0;
        numb.resize(n);
        for (int &i : numb) {
            cin >> i;
            sum += i;
        }

        if (sum % k != 0) {
            cout << 0 << endl;
            continue;
        }

        sort(numb.rbegin(), numb.rend()); 
        visited.assign(n, false);
        subset.assign(k, 0);

        cout << (Try(0) ? 1 : 0) << endl;
    }
    return 0;
}

/*
Trick lỏ:
#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int main() {
    tests() {
        int n, k, sum = 0;
        cin >> n >> k;
        while (n--) {
            int x;
            cin >> x;
            sum += x;
        }
        cout << (sum % k == 0 ? 1 : 0) << endl;
    }
    return 0;
}
*/
