#include <iostream>
using namespace std;

char end_char;
int len;
string current;

void generate() {
    if (current.length() == len) {
        cout << current << '\n';
        return;
    }
    
    char start = current.empty() ? 'A' : current.back();
    
    for (char c = start; c <= end_char; ++c) {
        current.push_back(c);
        generate();
        current.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> end_char >> len;
    current.reserve(len); 
    
    generate();
    return 0;
}