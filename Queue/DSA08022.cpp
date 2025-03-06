#include<bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int find(int a[], int n) {
    sort(a, a + n);  
    
    queue<int> q0, q1, q2;
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (a[i] % 3 == 0) q0.push(a[i]);
        else if (a[i] % 3 == 1) q1.push(a[i]);
        else q2.push(a[i]);
    }

    if (sum % 3 == 1) {
        if (!q1.empty()) 
            q1.pop();
        else {
            if (q2.size() >= 2) {
                q2.pop();
                q2.pop();
            }
            else
                return 0;
        }
    } 
    else if (sum % 3 == 2) {
        if (!q2.empty()) 
            q2.pop();
        else {
            if (q1.size() >= 2) {
                q1.pop();
                q1.pop();
            }
            else
                return 0;
        }
    }

    int aux[n], top = 0;
    
    while (!q0.empty()) { 
        aux[top++] = q0.front(); 
        q0.pop(); 
    }
    while (!q1.empty()) { 
        aux[top++] = q1.front(); 
        q1.pop(); 
    }
    while (!q2.empty()) { 
        aux[top++] = q2.front(); 
        q2.pop(); 
    }

    if (top > 0) {
        sort(aux, aux + top, greater<int>());
        for (int i = 0; i < top; i++) 
            cout << aux[i];
        
        cout << endl;
        return 1;
    }
    return 0;
}

int main() {
    fastio();
    tests() {
        int n;
        cin >> n; 
        
        int a[n];
        for (int &x : a) cin >> x; 
        
        if (find(a, n) == 0) 
            cout << -1 << endl;  
    }
    
    return 0;
}
