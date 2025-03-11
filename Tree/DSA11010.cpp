#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

bool checkEdges(int E) {
    return !((E + 2) & (E + 1));
}

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

bool BFS(Node* root) {
    if (!root) return true;

    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    int leafLevel = -1; 
    while (!q.empty()) {
        Node* node = q.front().first;
        int level = q.front().second;
        q.pop();

        if (!node->left && !node->right) {  
            if (leafLevel == -1) leafLevel = level;
            else if (leafLevel != level) return false; 
        } 
        else if (!node->left || !node->right) {  
            return false;
        }

        if (node->left) q.push({node->left, level + 1});
        if (node->right) q.push({node->right, level + 1});
    }
    return true;
}

int main() {
    fastio()
    tests() {
        int E;
        cin >> E;

        Node* root = nullptr;
        while (E--) {
            int u, v;
            char x;
            cin >> u >> v >> x;

            if (!root) root = new Node(u);

            root->insert(u, v, x);
        }

        cout << (BFS(root) ? "Yes" : "No") << endl;

        root->deleteTree();
        delete root;
    }
    return 0;
}