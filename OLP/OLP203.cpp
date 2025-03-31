#include <iostream>
using namespace std;

int64_t getValueAt(int64_t x, int64_t y) {
    int64_t diag = x + y - 1;
    int64_t start = (diag * (diag - 1)) / 2 + 1; 
    return start + y - 1;
}

pair<int64_t, int64_t> findCoordinates(int64_t z) {
    int64_t diag = 1;
    while ((diag * (diag + 1)) / 2 < z) ++diag;
    
    int64_t start = (diag * (diag - 1)) / 2 + 1;
    int64_t offset = z - start;
    
    return make_pair(diag - offset, 1 + offset);
}

int main() {
    int64_t x, y, z;
    cin >> x >> y >> z;
    
    cout << getValueAt(x, y) << "\n";
    auto [row, col] = findCoordinates(z);
    cout << row << " " << col << "\n";
    
    return 0;
}