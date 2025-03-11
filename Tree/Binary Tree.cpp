#include <bits/stdc++.h>
using namespace std;

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

    void NLR() {
        if (this == nullptr) return;  
        cout << this->data;
        if (this->left) this->left->LNR();
        if (this->right) this->right->LNR();
    }
    
    void LNR() {
        if (this == nullptr) return;  
        if (this->left) this->left->LNR();
        cout << this->data;
        if (this->right) this->right->LNR();
    }
    
    void LRN() {
        if (this == nullptr) return;  
        if (this->left) this->left->LNR();
        if (this->right) this->right->LNR();
        cout << this->data;
    }
};

int main() {
    return 0;
}
