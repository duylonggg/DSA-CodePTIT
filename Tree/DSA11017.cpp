#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}

    void insert(int val) {
        if (val < data) {
            if (!left) left = new Node(val);
            else left->insert(val);
        } else {
            if (!right) right = new Node(val);
            else right->insert(val);
        }
    }

    void postOrder() {
        if (left) left->postOrder();
        if (right) right->postOrder();
        cout << data << " ";
    }

    void deleteTree() {
        if (this->left) this->left->deleteTree();
        if (this->right) this->right->deleteTree();
        delete this;
    }
};

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int& _: A) cin >> _;

    Node* root = new Node(A[0]);
    for (int i = 1; i < N; ++i) root->insert(A[i]);

    root->postOrder();
    cout << endl;

    root->deleteTree();
}

int main() {
    fastio();
    tests() {
        solve();
    }    
    return 0;
}