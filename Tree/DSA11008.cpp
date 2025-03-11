#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), right(nullptr), left(nullptr) {}

    Node* search(int val) {
        if (this == nullptr) return nullptr;
        if (this->data == val) return this;

        Node* leftSearch = this->left ? this->left->search(val) : nullptr;
        if (leftSearch) return leftSearch;

        return this->right ? this->right->search(val) : nullptr;
    }
    
    void insert(int root, int val, char dir) {
        Node* par = search(root);
        if (!par) return;

        dir == 'L' ? (!par->left && (par->left = new Node(val))) : (!par->right && (par->right = new Node(val)));
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

int leafLevel = -1;
bool isSameLevel = true;

void DFS(Node* root, int level) {
    if (!root) return;

    if (!root->left and !root->right) {
        if (leafLevel == -1) leafLevel = level;
        else if (leafLevel != level) isSameLevel = false;
    }

    DFS(root->left, level + 1);
    DFS(root->right, level + 1);
}

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

            if (!i) root = new Node(u);

            root->insert(u, v, x);
        }
        
        leafLevel = -1;
        isSameLevel = true;
        DFS(root, 0);

        cout << isSameLevel << endl;

        root->deleteTree();
        delete root;
    }
    return 0;
}