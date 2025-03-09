#include <bits/stdc++.h>
using namespace std;

string addBig(string a, string b) {
    string res = "";
    int carry = 0, i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';
        res.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

string multiplyBig(string a, string b) {
    int n = a.size(), m = b.size();
    vector<int> res(n + m, 0);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int mul = (a[i] - '0') * (b[j] - '0') + res[i + j + 1];
            res[i + j + 1] = mul % 10;
            res[i + j] += mul / 10;
        }
    }
    string ans = "";
    for (int num : res)
        if (!(ans.empty() && num == 0))
            ans.push_back(num + '0');
    return ans.empty() ? "0" : ans;
}

string catalanDP(int n) {
    vector<string> dp(n + 1, "0");
    dp[0] = "1"; 
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < i; ++j)
            dp[i] = addBig(dp[i], multiplyBig(dp[j], dp[i - j - 1]));
    return dp[n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << catalanDP(n) << '\n';
    }
    return 0;
}