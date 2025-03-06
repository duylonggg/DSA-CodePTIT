#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

void mergePart(int* arr, int l, int mid, int r) {
    int i = l, j = mid + 1, idx = 0;
    int tmp[r - l + 1]; 

    while (i <= mid && j <= r) {
        tmp[idx++] = (arr[i] < arr[j] ? arr[i++] : arr[j++]);
    }

    while (i <= mid) tmp[idx++] = arr[i++];
    while (j <= r) tmp[idx++] = arr[j++];

    for (int i = 0; i < idx; ++i) 
        arr[l + i] = tmp[i]; 
}

void mergeSort(int* arr, int l, int r) {
    if (l >= r) return;

    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    mergePart(arr, l, mid, r);
}

int main() {
    fastio()
    tests() {
        int n;
        cin >> n;
        
        vector<int> arr(n);
        for (int& i : arr) cin >> i;

        mergeSort(arr.data(), 0, n - 1); 

        for (int i : arr) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
