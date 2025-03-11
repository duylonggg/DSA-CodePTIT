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
        Node* par = this->search(root);
        if (!par) return;

        dir == 'L' ? (!par->left and (par->left = new Node(val))) : (!par->right and (par->right = new Node(val)));
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

bool isFullTree(Node* root) {
    if (!root) return true;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        if ((cur->left && !cur->right) || (!cur->left && cur->right)) return false;

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    return true;
}

int main() {
    fastio();
    tests() {
        int n;
        cin >> n;

        Node* root = nullptr;
        while (n--) {
            int u, v;
            char x;
            cin >> u >> v >> x;

            if (!root) root = new Node(u);

            root->insert(u, v, x);
        }

        cout << isFullTree(root) << endl;

        root->deleteTree();
        delete root;
    }
    return 0;
}
