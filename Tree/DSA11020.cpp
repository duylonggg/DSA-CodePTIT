#include <bits/stdc++.h>
using namespace std;

#define tests() int test_cases; cin >> test_cases; while (test_cases--)

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
    
    void insert(int val) {
        if (val < data) {
            if (!left) left = new Node(val);
            else left->insert(val);
        } else {
            if (!right) right = new Node(val);
            else right->insert(val);
        }
    }

    void inorder(vector<int>& result) {
        if (left) left->inorder(result);
        result.push_back(data);
        if (right) right->inorder(result);
    }

    void deleteTree() {
        if (left) left->deleteTree();
        if (right) right->deleteTree();
        delete this;
    }
};

bool isInorderBST(vector<int>& A) {
    if (A.empty()) return true;

    Node* root = new Node(A[0]);

    for (int i = 1; i < A.size(); ++i) {
        root->insert(A[i]);
    }

    vector<int> inorderResult;
    root->inorder(inorderResult);

    bool isValid = (A == inorderResult);

    root->deleteTree(); 
    return isValid;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    tests() {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int &x : A) cin >> x;

        cout << isInorderBST(A) << endl;
    }

    return 0;
}
