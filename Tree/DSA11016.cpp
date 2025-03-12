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

    void buildTree(int par, int child, char dir) {
        if (this == nullptr) return;

        if (this->data == par) {
            if (dir == 'L') this->left = new Node(child);
            else this->right = new Node(child);
            return;
        }

        if (this->left) this->left->buildTree(par, child, dir);
        if (this->right) this->right->buildTree(par, child, dir);
    }

    void toBST() {
        vector<int> values;
    
        function<void(Node*)> inorder = [&](Node* node) {
            if (!node) return;
            inorder(node->left);
            values.push_back(node->data);
            inorder(node->right);
        };

        inorder(this);
        sort(values.begin(), values.end());

        int idx = 0;
        function<void(Node*)> buildBST = [&](Node* node) {
            if (!node) return;
            buildBST(node->left);
            node->data = values[idx++];
            buildBST(node->right);
        };

        buildBST(this);
    }

    void LNR() {
        if (this == nullptr) return;
        if (this->left) this->left->LNR();
        cout << this->data << ' ';
        if (this->right) this->right->LNR();
    }

    void deleteTree() {
        if (this->left) {
            this->left->deleteTree();
            delete this->left;
            this->left = nullptr;
        }
        if (this->right) {
            this->right->deleteTree();
            delete this->right;
            this->right = nullptr;
        }
    }
};

int main() {
    fastio()
    tests() {
        int N;
        cin >> N;

        Node* root = nullptr;
        while (N--) {
            int par, child;
            char dir;
            cin >> par >> child >> dir;

            if (!root) root = new Node(par);
            root->buildTree(par, child, dir);
        }

        root->toBST();
        root->LNR();
        cout << endl;

        root->deleteTree();
        root = nullptr;
    }
    return 0;
}
