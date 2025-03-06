#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int find_k(int* a, int* end_a, int* b, int* end_b, int k) {
    if (a == end_a) return b[k];  
    if (b == end_b) return a[k]; 
    
    int mid_a = (end_a - a) / 2;
    int mid_b = (end_b - b) / 2;

    if (mid_a + mid_b < k) {
        if (a[mid_a] < b[mid_b]) 
            return find_k(a + mid_a + 1, end_a, b, end_b, k - mid_a - 1);
        else 
            return find_k(a, end_a, b + mid_b + 1, end_b, k - mid_b - 1);
    } else {
        if (a[mid_a] < b[mid_b]) 
            return find_k(a, end_a, b, b + mid_b, k);
        else 
            return find_k(a, a + mid_a, b, end_b, k);
    }
}

int main() {
    fastio();
    tests() {
        int k, n, m;
        cin >> n >> m >> k;

        int *a = new int[n];
        int *b = new int[m];

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        cout << find_k(a, a + n, b, b + m, k - 1) << endl;

        delete[] a;
        delete[] b;
    }
    return 0;
}
