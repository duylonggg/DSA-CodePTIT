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

    static Node* buildBalancedBST(vector<int>& arr, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        Node* root = new Node(arr[mid]);
        root->left = buildBalancedBST(arr, left, mid - 1);
        root->right = buildBalancedBST(arr, mid + 1, right);
        return root;
    }

    void deleteTree() {
        if (left) left->deleteTree();
        if (right) right->deleteTree();
        delete this;
    }
};

int main() {
    fastio();
    tests() {
        int N;
        cin >> N;

        vector<int> v(N);
        for (int& _: v) cin >> _;

        sort(v.begin(), v.end());

        Node* root = Node::buildBalancedBST(v, 0, N - 1);

        cout << root->data << endl;

        root->deleteTree();
    }
    return 0;
}