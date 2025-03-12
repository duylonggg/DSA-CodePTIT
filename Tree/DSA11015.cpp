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

    int64_t sumLeafToLeafUtil(int64_t &MAX) {
        if (!this) return 0;

        int64_t L = this->left ? this->left->sumLeafToLeafUtil(MAX) : 0;
        int64_t R = this->right ? this->right->sumLeafToLeafUtil(MAX) : 0;

        if (!this->left && !this->right) return this->data;
        if (!left) return R + this->data;
        if (!right) return L + this->data;

        MAX = max(MAX, L + R + this->data);
        return max(L, R) + this->data;
    }

    int64_t sumLeafToLeaf() {
        int64_t MAX = LLONG_MIN;
        int64_t result = sumLeafToLeafUtil(MAX);
        return (MAX == LLONG_MIN) ? result : MAX;
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
    fastio();
    tests() {
        int N, par, child;
        char dir;
        cin >> N;

        Node* root = nullptr;

        while (N--) {
            cin >> par >> child >> dir;

            if (!root) root = new Node(par);

            root->buildTree(par, child, dir);
        }

        cout << root->sumLeafToLeaf() << endl;

        root->deleteTree();
        delete root;
    }
    return 0;
}
