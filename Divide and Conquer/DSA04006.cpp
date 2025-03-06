#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int64_t length(int64_t N) {
    if (N == 1) return 1; 
    return 2 * length(N / 2) + 1;
}

int64_t countOnes(int64_t N, int64_t L, int64_t R, int64_t pos = 1) {
    if (N == 0) return 0;  
    
    int64_t len = length(N);
    int64_t mid = pos + (len - 1) / 2; 

    if (R < pos || L > pos + len - 1) return 0; 

    int64_t ones = 0;
    
    if (L <= mid && mid <= R) ones += (N % 2); 
    ones += countOnes(N / 2, L, R, pos);
    ones += countOnes(N / 2, L, R, mid + 1);

    return ones;
}

int main() {
    fastio();
    tests() {
        int64_t N, L, R;
        cin >> N >> L >> R;
        cout << countOnes(N, L, R) << endl;
    }
    return 0;
}
