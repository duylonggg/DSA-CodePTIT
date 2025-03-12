#include <bits/stdc++.h>
using namespace std;

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

    bool compareTo(Node* other) {
        if (this == nullptr || other == nullptr)
            return this == other;

        if (this->data != other->data)
            return false;

        return (this->left ? this->left->compareTo(other->left) : other->left == nullptr) and
               (this->right ? this->right->compareTo(other->right) : other->right == nullptr);
    }

    bool isLeaf() {
        return !this->left && !this->right;
    }
    
    int64_t sumRightLeaves() {
        if (!this) return 0;

        int64_t sum = 0;
        if (this->right) {
            if (this->right->isLeaf()) sum += this->right->data;
            else sum += this->right->sumRightLeaves();
        }
        if (this->left) sum += this->left->sumRightLeaves();

        return sum;
    }

    int64_t sumLeftLeaves() {
        if (!this) return 0;

        int64_t sum = 0;
        if (this->left) {
            if (this->left->isLeaf()) sum += this->left->data;
            else sum += this->left->sumLeftLeaves();
        }
        if (this->right) sum += this->right->sumLeftLeaves();

        return sum;
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

    void NLR() {
        if (this == nullptr) return;  
        cout << this->data;
        if (this->left) this->left->NLR();
        if (this->right) this->right->NLR();
    }
    
    void LNR() {
        if (this == nullptr) return;  
        if (this->left) this->left->LNR();
        cout << this->data;
        if (this->right) this->right->LNR();
    }
    
    void LRN() {
        if (this == nullptr) return;  
        if (this->left) this->left->LRN();
        if (this->right) this->right->LRN();
        cout << this->data;
    }
};

int main() {
    return 0;
}
