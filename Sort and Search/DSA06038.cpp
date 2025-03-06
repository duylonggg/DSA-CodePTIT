#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);

inline int merge_part(int* a, int l, int r, int mid) {
    int left = l, right = mid, idx = 0;
    int res = 0;

    int tmp[r - l + 1];
    while (left < mid and right <= r) {
        if (a[left] <= a[right]) {
            tmp[idx++] = a[left++];
        } else {
            tmp[idx++] = a[right++];
            res += mid - left;
        }
    }

    while (left < mid) tmp[idx++] = a[left++];
    while (right <= r) tmp[idx++] = a[right++];

    for (int i = 0; i < idx; ++i)
        a[l + i] = tmp[i];

    return res;
}

inline int merge_sort(int* a, int l, int r) {
    int res = 0;
    if (l < r) {
        int mid = (l + r) / 2;
        res += merge_sort(a, l, mid);
        res += merge_sort(a, mid + 1, r);
        res += merge_part(a, l, r, mid + 1);
    }
    return res;
}

int main() {
    fastio();
    
    int n;
    cin >> n;

    int a[n + 1], b[n + 1], idx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if ((a[i] & 1) ^ 1) b[idx++] = a[i]; 
    }

    int res = merge_sort(b, 0, idx - 1);

    int even_cont = 0;
    a[n] = 1;
    for (int i = 1; i <= n; ++i) {
        if ((a[i] & 1) ^ 1 and (a[i - 1] & 1) ^ 1) ++even_cont;
        else if ((a[i] & 1) and (a[i - 1] & 1) ^ 1) {
            res -= merge_sort(a, i - 1 - even_cont, i - 1);
            even_cont = 0;
        }
    }

    cout << res;

    return 0;
}
