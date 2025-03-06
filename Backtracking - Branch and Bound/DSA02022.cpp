#include <bits/stdc++.h>
using namespace std;

string day[] = {"02", "20", "22"};
string month = "02";
vector<string> year;

void gen_year(string y = "2") {
    if (y.size() == 4) {
        year.push_back(y);
        return;
    }

    gen_year(y + "0");
    gen_year(y + "2");
}

int main() {
    gen_year();

    for (int i = 0; i < 3; ++i) {
        for (auto y : year) {
            string date = day[i] + '/' + month + '/' + y;
            cout << date << endl;
        }
    }

    return 0;
}
