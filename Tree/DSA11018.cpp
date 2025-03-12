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
        if (val < this->data) {
            if (!this->left) this->left = new Node(val);
            else this->left->insert(val);
        } else {
            if (!this->right) this->right = new Node(val);
            else this->right->insert(val);
        }
    }

    void preOrder() {
        if (!this) return;
        cout << this->data << ' ';
        if (this->left) this->left->preOrder();
        if (this->right) this->right->preOrder();
    }

    void deleteTree() {
        if (this->left) this->left->deleteTree();
        if (this->right) this->right->deleteTree();
        delete this;
    }
};

int main() {
    fastio()
    tests() {
        int N;
        cin >> N;

        vector<int> levelOrder(N);
        for (int& _: levelOrder) cin >> _;

        Node* root = new Node(levelOrder[0]);
        for (int i = 1; i < N; ++i)
            root->insert(levelOrder[i]);

        root->preOrder();
        cout << endl;

        root->deleteTree();
    }
    return 0;
}