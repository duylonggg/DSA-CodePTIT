#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; cin.ignore(); while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int getCoef(const string& str) {
    size_t pos = str.find('*');
    return stoi(str.substr(0, pos));
}

int getExp(const string& str) {
    size_t pos = str.find('^');
    return stoi(str.substr(pos + 1));
}

void processPolynomial(const string& input, stack<pair<int, int>>& expr) {
    stringstream ss(input);
    string str;
    stack<pair<int, int>> tmp;

    while (ss >> str) {
        if (str == "+") continue;

        int coef = getCoef(str);
        int exp = getExp(str);

        while (!expr.empty() and exp < expr.top().second) {
            tmp.push(expr.top());
            expr.pop();
        }
        if (!expr.empty() and exp == expr.top().second) {
            coef += expr.top().first;
            expr.pop();
        }

        expr.push({coef, exp});

        while (!tmp.empty()) {
            expr.push(tmp.top());
            tmp.pop();
        }
    }
}

int main() {
    fastio();
    tests() {
        string str1, str2;
        getline(cin, str1);
        getline(cin, str2);

        stack<pair<int, int>> expr;
        processPolynomial(str1, expr);
        processPolynomial(str2, expr);

        auto [coef, exp] = expr.top();
        expr.pop();
        cout << coef << "*x^" << exp;
        while (!expr.empty()) {
            auto [coef, exp] = expr.top();
            cout << " + " << coef << "*x^" << exp;
            expr.pop();
        }
        cout << endl;
    }
    return 0;
}
