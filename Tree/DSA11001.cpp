#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char val) : data(val), left(nullptr), right(nullptr) {}

    void LNR() {
        if (this == nullptr) return;  
        if (this->left) this->left->LNR();
        cout << this->data;
        if (this->right) this->right->LNR();
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
    fastio()
    tests() {
        string postfix;
        cin >> postfix;

        stack<Node*> stk;
        for (char c : postfix) {
            Node* ope = new Node(c);
            if (isalnum(c)) {
                stk.push(ope);
            } else {
                Node* rightNode = stk.top(); stk.pop();
                Node* leftNode = stk.top(); stk.pop();

                ope->left = leftNode;
                ope->right = rightNode;

                stk.push(ope);
            }
        }

        stk.top()->LNR();
        stk.top()->deleteTree();
        delete stk.top();
        cout << endl;
        stk.pop();
    }
    return 0;
}