#include <bits/stdc++.h>
using namespace std;

int n, k, minDiff = INT_MAX;
vector<string> v;
vector<int> per;

void Try() {
    do {
        vector<int> numb(n);
        for (int i = 0; i < n; ++i) {
            string newStr = "";
            for (int j = 0; j < k; ++j) 
                newStr += v[i][per[j]]; 
            
            numb[i] = stoi(newStr);
        }

        int maxVal = *max_element(numb.begin(), numb.end());
        int minVal = *min_element(numb.begin(), numb.end());
        minDiff = min(minDiff, maxVal - minVal);
    } while (next_permutation(per.begin(), per.end()));
}

int main() {
    cin >> n >> k;
    v.resize(n);
    per.resize(k);
    
    for (string& str : v) cin >> str;

    iota(per.begin(), per.end(), 0);

    Try();

    cout << minDiff;
    
    return 0;
}
