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

    void buildTree(int val) {
        if (val < this->data) {
            if (!this->left) this->left = new Node(val);
            else this->left->buildTree(val);
        } else {
            if (!this->right) this->right = new Node(val);
            else this->right->buildTree(val);
        }
    }

    int treeHeight() {
        if (!this) return -1; 
        int leftHeight = this->left ? this->left->treeHeight() : -1;
        int rightHeight = this->right ? this->right->treeHeight() : -1;
        return 1 + max(leftHeight, rightHeight);
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

        vector<int> preOrder(N);
        for (int& _: preOrder) cin >> _;

        Node* root = new Node(preOrder[0]);
        for (int i = 1; i < N; ++i)
            root->buildTree(preOrder[i]);

        cout << root->treeHeight() << endl;
        root->deleteTree();
    }
    return 0;
}
