#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    
    map<int, int> events;
    for (int i = 0; i < N; ++i) {
        int U, V;
        cin >> U >> V;
        ++events[U];      
        --events[V + 1]; 
    }

    map<int, int> badge_count;
    int current_badges = 0;
    for (auto [pos, change] : events) {
        current_badges += change;
        badge_count[pos] = current_badges;
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int C;
        cin >> C;
        
        auto it = badge_count.upper_bound(C);
        if (it == badge_count.begin()) cout << "0\n"; 
        else cout << prev(it)->second << "\n";  
    }
    return 0;
}
