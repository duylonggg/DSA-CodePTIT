#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}

    void buildTree(int val) {
        if (val < this->data) {
            if (this->left == nullptr) this->left = new Node(val);
            else this->left->insert(val);
        } else {
            if (this->right == nullptr) this->right = new Node(val);
            else this->right->insert(val);
        }
    }

    static Node* buildBalancedBST(vector<int>& arr, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        Node* root = new Node(arr[mid]);
        root->left = buildBalancedBST(arr, left, mid - 1);
        root->right = buildBalancedBST(arr, mid + 1, right);
        return root;
    }

    bool isLeaf() {
        return !this->left and !this->right;
    }

    void findLeaves() {
        if (this->isLeaf()) {
            cout << this->data << ' ';
            return;
        }

        if (this->left) this->left->findLeaves();
        if (this->right) this->right->findLeaves();
    }

    int internalNode() {
        if (this == nullptr || this->isLeaf()) return 0;
    
        int node = 1; 
        if (this->left) node += this->left->internalNode();
        if (this->right) node += this->right->internalNode();
    
        return node;
    }

    int treeHeight() {
        if (!this) return -1; 
        int leftHeight = this->left ? this->left->treeHeight() : -1;
        int rightHeight = this->right ? this->right->treeHeight() : -1;
        return 1 + max(leftHeight, rightHeight);
    }

    void preOrder() {
        if (!this) return;
        cout << this->data << ' ';
        if (this->left) this->left->preOrder();
        if (this->right) this->right->preOrder();
    }

    void inOrder() {
        if (!this) return;
        if (this->left) this->left->inOrder();
        cout << this->data << ' ';
        if (this->right) this->right->inOrder();
    }

    void postOrder() {
        if (!this) return;
        if (this->left) this->left->postOrder();
        if (this->right) this->right->postOrder();
        cout << this->data << ' ';
    }

    void deleteTree() {
        if (this->left) this->left->deleteTree();
        if (this->right) this->right->deleteTree();
        delete this;
    }
};

int main() {
    return 0;
}