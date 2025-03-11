#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}

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

unordered_map<int, int> inorderIndex;

Node* buildTree(vector<int>& inorder, vector<int>& levelOrder, int start, int end) {
    if (start > end) return nullptr;

    queue<Node*> q;
    unordered_set<int> inorderSet(inorder.begin() + start, inorder.begin() + end + 1);

    for (int val : levelOrder) {
        if (inorderSet.count(val)) {
            Node* root = new Node(val);
            int rootIdx = inorderIndex[val];

            root->left = buildTree(inorder, levelOrder, start, rootIdx - 1);
            root->right = buildTree(inorder, levelOrder, rootIdx + 1, end);
            return root;
        }
    }
    return nullptr;
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<int> inorder(n), levelOrder(n);
        for (int& x : inorder) cin >> x;
        for (int& x : levelOrder) cin >> x;

        for (int i = 0; i < n; i++) inorderIndex[inorder[i]] = i;

        Node* root = buildTree(inorder, levelOrder, 0, n - 1);
        
        postorder(root);

        root->deleteTree();
        delete root;
        
        cout << endl;
    }
    return 0;
}