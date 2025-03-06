#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio();
    tests() {
        int N;
        cin >> N;
        vector<tuple<int, int, int>> work(N);

        for (int i = 0; i < N; ++i) {
            int jobID, deadline, profit;
            cin >> jobID >> deadline >> profit;
            work[i] = {profit, deadline, jobID}; 
        }

        sort(work.rbegin(), work.rend());

        int max_deadline = 0;
        for (auto &[p, d, j] : work) max_deadline = max(max_deadline, d);

        vector<bool> slot(max_deadline + 1, false);
        int total_profit = 0, count_jobs = 0;

        for (auto &[p, d, j] : work) {
            for (int k = min(d, max_deadline); ~k; --k) {
                if (!slot[k]) {
                    slot[k] = true;
                    total_profit += p;
                    ++count_jobs;
                    break;
                }
            }
        }

        cout << count_jobs << " " << total_profit << endl;
    }
    return 0;
}
