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

    Node* search(int val) {
        if (this == nullptr) return nullptr;
        if (this->data == val) return this;

        Node* leftSearch = this->left ? this->left->search(val) : nullptr;
        if (leftSearch) return leftSearch;

        return this->right ? this->right->search(val) : nullptr;
    }

    void insert(int root, int val, char dir) {
        Node* parent = this->search(root);
        if (!parent) return; 

        if (dir == 'L') {
            if (!parent->left) parent->left = new Node(val);
        } else {
            if (!parent->right) parent->right = new Node(val);
        }
    }

    void deleteTree() {
        if (this->left) {
            this->left->deleteTree();
            delete this->left;
        }
        if (this->right) {
            this->right->deleteTree();
            delete this->right;
        }
    }
};

int main() {
    fastio()
    tests() {
        int n;
        cin >> n;

        Node* root;
        for (int i = 0; i < n; ++i) {
            int u, v;
            char x;
            cin >> u >> v >> x;
            
            if (i == 0) root = new Node(u);

            root->insert(u, v, x);
        }

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();

            cout << cur->data << ' ';
            
            if (cur->left != nullptr) q.push(cur->left);
            if (cur->right != nullptr) q.push(cur->right);
        }

        root->deleteTree();
        delete root;

        cout << endl;
    }
    return 0;
}