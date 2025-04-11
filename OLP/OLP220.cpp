#include <bits/stdc++.h>

#pragma GCC optimize("Ofast, unroll-loops")

using namespace std;

int d[1005][1005];
int cnt[1005][1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) {
		int n, m, k;
		string s;
		
		cin >> n >> m >> k >> s;

		int len = s.size();
		vector<int> dr(len + 5), dc(len + 5);
		
		for (int i = 0; i < len; ++i) {
			dr[i + 1] = dr[i];
			dc[i + 1] = dc[i];
			if (s[i] == 'U')
				--dr[i + 1];
			else if (s[i] == 'D')
				++dr[i + 1];
			else if (s[i] == 'L')
				--dc[i + 1];
			else if (s[i] == 'R')
				++dc[i + 1];
		}

		int mnr = 0, mxr = 0, mnc = 0, mxc = 0;
		
		for (int i = 0; i <= len; ++i) {
			mnr = min(mnr, dr[i]);
			mxr = max(mxr, dr[i]);
			mnc = min(mnc, dc[i]);
			mxc = max(mxc, dc[i]);
		}

		int r1 = 1 - mnr;
		int r2 = n - mxr;
		int c1 = 1 - mnc;
		int c2 = m - mxc;
		long long x = 0;

		if (r1 <= r2 and c1 <= c2)
			x = 1LL * (r2 - r1 + 1) * (c2 - c1 + 1);

		if (!x) {
			if (!k)
				cout << 1LL * n * m << '\n';
			else
				cout << 0 << '\n';
			continue;
		}

		if (k > x) {
			cout << 0 << '\n';
			continue;
		}

		unordered_set<long long> st;
		const int off = 1e6;
		vector<pair<int, int>> v;

		for (int i = 0; i <= len; ++i) {
			int r = dr[i], c = dc[i];
			long long key = 1LL * (r + off) * 2000001LL + (c + off);
			if (st.find(key) == st.end())
			{
				st.insert(key);
				v.emplace_back(make_pair(r, c));
			}
		}

		for (int i = 0; i <= n + 1; ++i)
			for (int j = 0; j <= m + 1; ++j)
				d[i][j] = 0;

		for (auto& p: v) {
			int r = p.first, c = p.second;
			int x1 = r1 + r, x2 = r2 + r;
			int y1 = c1 + c, y2 = c2 + c;

			if (x1 < 1)
				x1 = 1;
			if (x2 > n)
				x2 = n;
			if (y1 < 1)
				y1 = 1;
			if (y2 > m)
				y2 = m;

			if (x1 > x2 or y1 > y2)
				continue;

			++d[x1][y1];
			--d[x1][y2 + 1];
			--d[x2 + 1][y1];
			++d[x2 + 1][y2 + 1];
		}

		for (int i = 1; i <= n; ++i) {
			int sum = 0;
			for (int j = 1; j <= m; ++j) {
				sum += d[i][j];
				if (i == 1)
					cnt[i][j] = sum;
				else
					cnt[i][j] = cnt[i - 1][j] + sum;
			}
		}

		int tmp = x - k;
		long long ans = 0;
		
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (cnt[i][j] == tmp)
					++ans;

		cout << ans << '\n';
	}
	return 0;
}