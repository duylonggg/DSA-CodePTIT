#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int64_t mergePart(int64_t* arr, int l, int mid, int r) {
    int64_t cnt = 0;
    int idx = 0, i = l, j = mid + 1;
    int tmp[r - l + 1];

    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) tmp[idx++] = arr[i++];
        else {
            tmp[idx++] = arr[j++];
            cnt += (mid - i + 1); 
        }
    }

    while (i <= mid) tmp[idx++] = arr[i++];
    while (j <= r) tmp[idx++] = arr[j++];

    for (int i = 0; i < idx; ++i)
        arr[l + i] = tmp[i];

    return cnt;
}

int64_t mergeSort(int64_t* arr, int l, int r) {
    if (l >= r) return 0;

    int mid = (l + r) / 2;
    int64_t total = 0;
    total += mergeSort(arr, l, mid);
    total += mergeSort(arr, mid + 1, r);
    total += mergePart(arr, l, mid, r);

    return total;
}

int main() {
    fastio();
    tests() {
        int n;
        cin >> n;

        int64_t* arr = new int64_t[n];
        for (int i = 0; i < n; ++i) cin >> arr[i];

        cout << mergeSort(arr, 0, n - 1) << endl;

        delete[] arr;
    }
    return 0;
}
