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

    static Node* buildBalancedBST(vector<int>& v, int left, int right) {
        if (left > right) return nullptr;
        int mid = (left + right) >> 1;
        Node* root = new Node(v[mid]);
        root->left = buildBalancedBST(v, left, mid - 1);
        root->right = buildBalancedBST(v, mid + 1, right);
        return root;
    }

    void preOrder() {
        if (!this) return;
        cout << this->data << ' ';
        if (this->left) this->left->preOrder();
        if (this->right) this->right->preOrder();
    }

    void deleteTree() {
        if (this->left) this->left->deleteTree();
        if (this->right) this->right->deleteTree();
        delete this;
    }
};

int main() {
    fastio()
    tests() {
        int N;
        cin >> N;

        vector<int> v(N);
        for (int& _: v) cin >> _;

        sort(begin(v), end(v));

        Node* root = Node::buildBalancedBST(v, 0, N - 1);

        root->preOrder();
        root->deleteTree();
        cout << endl;
    }
    return 0;
}