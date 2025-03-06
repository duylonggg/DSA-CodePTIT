#include <bits/stdc++.h>
using namespace std;

#define tests() int test_cases; cin >> test_cases; cin.ignore(); while (test_cases--)

bool flag;
string ope = "+-*/";

bool check(const string& math) {
    int num1 = stoi(math.substr(0, 2)), 
        num2 = stoi(math.substr(5, 2)),
        num3 = stoi(math.substr(10, 2));

    if (math[3] == '+') return num1 + num2 == num3;
    if (math[3] == '-') return num1 - num2 == num3;
    if (math[3] == '/') return num2 != 0 and num1 % num2 == 0 and num1 / num2 == num3;
    if (math[3] == '*') return num1 * num2 == num3;

    return false;
}

void Try(string math, int pos = 0) {
    if (flag) return; 

    if (pos == math.size()) {
        if (check(math)) {
            cout << math << endl;
            flag = true;
        }
        return;
    }

    if (math[pos] != '?') {
        if (!flag) Try(math, pos + 1);
        return;
    }

    if (pos == 3) { 
        for (char c : ope) {
            math[pos] = c;
            if (!flag) Try(math, pos + 1);
        }
    } else if (!pos or pos == 5 or pos == 10) {
        for (char c = '1'; c <= '9'; ++c) {
            math[pos] = c;
            if (!flag) Try(math, pos + 1);
        }
    } else {
        for (char c = '0'; c <= '9'; ++c) {
            math[pos] = c;
            if (!flag) Try(math, pos + 1);
        }
    }
}

int main() {
    tests() {
        string math;
        getline(cin >> ws, math); 
        
        flag = false;  
        Try(math);
        
        if (!flag) cout << "WRONG PROBLEM!" << endl;
    }
    return 0;
}
