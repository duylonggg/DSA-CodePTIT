#include <bits/stdc++.h>
using namespace std;

int N, W, maxC;
vector<int> c, a, x;
string res;

void Try(int idx) {
    for (int i = 0; i <= 1; ++i) {
        x[idx] = i;
        
        if (idx == N - 1) {
            int totalW = 0, totalC = 0;
            string str = "";

            for (size_t j = 0; j < N; ++j) {
                str += to_string(x[j]) + " ";
                if (x[j]) {
                    totalW += a[j];
                    totalC += c[j];
                }
            }

            if (totalW == W and totalC > maxC) {
                maxC = totalC;
                res = str;
            }
        }
        else
            Try(idx + 1);
    }
}

int main() {
    cin >> N >> W;

    c.resize(N);
    a.resize(N);
    x.resize(N);

    for (int& i : c) cin >> i;
    for (int& i : a) cin >> i;

    Try(0);

    cout << maxC << endl << res;

    return 0;
}