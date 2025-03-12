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

    void deleteTree() {
        if (left) {
            left->deleteTree();
            delete left;
        }
        if (right) {
            right->deleteTree();
            delete right;
        }
    }
};

int main() {
    fastio()
    tests() {
        int n;
        cin >> n;

        Node* tree = nullptr;
        unordered_map<int, Node*> mp;

        while (n--) {
            int root, child;
            char dir;
            cin >> root >> child >> dir;

            if (!mp.count(root)) {
                mp[root] = new Node(root);
                if (!tree) tree = mp[root];
            }

            Node* parent = mp[root];
            Node* childNode = new Node(child);
            mp[child] = childNode;

            if (dir == 'L') parent->left = childNode;
            else parent->right = childNode;
        }

        cout << tree->sumRightLeaves() << endl;

        tree->deleteTree();
        delete tree;
        mp.clear();
    }
    return 0;
}
