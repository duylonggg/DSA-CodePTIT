#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

struct Node {
    string data;
    Node* left;
    Node* right;

    Node(string val) : data(val), right(nullptr), left(nullptr) {}
};

int evaluate(Node* root) {
    if (!root) return 0;

    if (isdigit(root->data[0])) {
        return stoi(root->data);
    }

    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);

    if (root->data == "+") return leftVal + rightVal;
    if (root->data == "-") return leftVal - rightVal;
    if (root->data == "*") return leftVal * rightVal;
    if (root->data == "/") return rightVal ? leftVal / rightVal : 0;

    return 0;
}

int main() {
    fastio()
    tests() {
        int n;
        cin >> n;

        vector<string> opes(n);
        for (string& ope : opes) cin >> ope;

        Node* root = new Node(opes[0]);
        queue<Node*> q;
        q.push(root);

        int idx = 1;
        while (idx < n) {
            Node* cur = q.front();
            q.pop();

            if (idx < n) {
                cur->left = new Node(opes[idx++]);
                q.push(cur->left);
            }
            if (idx < n) {
                cur->right = new Node(opes[idx++]);
                q.push(cur->right);
            }
        }

        cout << evaluate(root) << endl;
    }
    return 0;
}