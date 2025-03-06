#include <bits/stdc++.h>
using namespace std;

bool backtrack(vector<int>& A, int index, int target) {
    if (target == 0) return true; 
    if (index == A.size() or target < 0) return false;  

    return backtrack(A, index + 1, target - A[index]) or backtrack(A, index + 1, target);
}

bool canPartition(vector<int>& A) {
    int sum = accumulate(A.begin(), A.end(), 0);
    
    if (sum & 1) return false;
    
    sort(A.begin(), A.end());
    
    return backtrack(A, 0, sum >> 1);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        
        for (int i = 0; i < n; ++i) cin >> A[i];

        cout << (canPartition(A) ? "YES" : "NO") << '\n';
    }
    
    return 0;
}