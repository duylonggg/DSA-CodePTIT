#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);

bool check(string &str, string &str_cube) {
    size_t i = 0, j = 0;
    while (i < str.size() and j < str_cube.size()) {
        if (str[i] == str_cube[j]) ++j;
        ++i;
    }
    return j == str_cube.size();
}

long long findCube(const long long& n) {
    string str = to_string(n);
    
    for (long long i = cbrt(n); ~i; --i) {
        long long cube = i * i * i;
        string str_cube = to_string(cube);
        
        if (check(str, str_cube)) 
            return cube; 
    }

    return -1; 
}

int main() {
    fastio();
    tests() {
        long long n;
        cin >> n;
        cout << findCube(n) << endl;
    }
    return 0;
}
