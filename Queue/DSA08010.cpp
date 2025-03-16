#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int BFS(int N) {
    unordered_set<int> vis;
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq; 
    
    vis.insert(N);
    pq.push({0, N});  

    while (!pq.empty()) {
        auto [steps, N] = pq.top();
        pq.pop();

        if (N == 1) return steps;

        if (!vis.count(N - 1)) {
            if (N - 1 == 1) return steps + 1;
            vis.insert(N - 1);
            pq.push({steps + 1, N - 1});
        }

        for (int i = sqrt(N); i >= 2; --i) { 
            if (N % i == 0) {
                if (!vis.count(N / i)) {
                    if (N / i == 1) return steps + 1;
                    vis.insert(N / i);
                    pq.push({steps + 1, N / i});
                }
            }
        }
    }
}

int main() {
    fastio();
    tests() {
        int N;
        cin >> N;
        cout << BFS(N) << endl;
    }
    return 0;
}
