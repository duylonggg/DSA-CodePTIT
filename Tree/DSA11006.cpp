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

int main() {
    fastio()
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

        stack<Node*> stk1, stk2;
        stk1.push(root);

        while (!stk1.empty() || !stk2.empty()) {
            while (!stk1.empty()) {
                Node* cur = stk1.top();
                stk1.pop();

                cout << cur->data << ' ';

                if (cur->right) stk2.push(cur->right);
                if (cur->left) stk2.push(cur->left);
            }
            while (!stk2.empty()) {
                Node* cur = stk2.top();
                stk2.pop();

                cout << cur->data << ' ';

                if (cur->left) stk1.push(cur->left);
                if (cur->right) stk1.push(cur->right);
            }
        }

        cout << endl;
    }
    return 0;
}