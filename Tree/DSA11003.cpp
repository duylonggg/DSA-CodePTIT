#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

void buildPostorder(const vector<int>& inorder, const vector<int>& preorder, 
                    unordered_map<int, int>& inorderPos, int inLeft, int inRight, 
                    int& preIndex, vector<int>& postorder) {
    if (inLeft > inRight) return; 

    int rootValue = preorder[preIndex++]; 
    int rootIdx = inorderPos[rootValue]; 

    buildPostorder(inorder, preorder, inorderPos, inLeft, rootIdx - 1, preIndex, postorder);
    buildPostorder(inorder, preorder, inorderPos, rootIdx + 1, inRight, preIndex, postorder);

    postorder.push_back(rootValue);
}

int main() {
    fastio();
    tests() {
        int n;
        cin >> n;

        vector<int> inorder(n), preorder(n);
        for (int& _: inorder) cin >> _;  
        for (int& _: preorder) cin >> _;

        unordered_map<int, int> inorderPos;
        for (int i = 0; i < n; i++) {
            inorderPos[inorder[i]] = i;
        }

        vector<int> postorder;
        int preIndex = 0;
        buildPostorder(inorder, preorder, inorderPos, 0, n - 1, preIndex, postorder);

        for (int _ : postorder) cout << _ << ' ';
        cout << endl;
    }
    return 0;
}
