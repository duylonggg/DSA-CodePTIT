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

    void insert(int root, int child, char dir) {
        Node* par = this->search(root);
        if (!par) return;

        dir == 'L' ? (!par->left and (par->left = new Node(child))) : (!par->right and (par->right = new Node(child)));
    }

    bool compareTo(Node* other) {
        if (this == nullptr || other == nullptr)
            return this == other;

        if (this->data != other->data)
            return false;

        return (this->left ? this->left->compareTo(other->left) : other->left == nullptr) and
               (this->right ? this->right->compareTo(other->right) : other->right == nullptr);
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
        int E1, E2, root, child;
        char dir;

        Node* tree1 = nullptr;
        Node* tree2 = nullptr;

        cin >> E1;
        while (E1--) {
            cin >> root >> child >> dir;

            if (!tree1) tree1 = new Node(root);

            tree1->insert(root, child, dir);
        }

        cin >> E2;
        while (E2--) {
            cin >> root >> child >> dir;

            if (!tree2) tree2 = new Node(root);

            tree2->insert(root, child, dir);
        }
            
        cout << tree1->compareTo(tree2) << endl;

        tree1->deleteTree();
        tree2->deleteTree();
        delete tree1;
        delete tree2;
    }
    return 0;
}