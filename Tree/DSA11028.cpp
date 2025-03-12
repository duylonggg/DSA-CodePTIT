#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

struct Node {
    int data;
    vector<Node*> children;

    Node(int val) : data(val) {}

    int countHeight() {
        int maxDepth = 0;
        for (Node* child : children) {
            maxDepth = max(maxDepth, child->countHeight());
        }
        return maxDepth + 1;
    }
};

int main() {
    fastio();
    tests() {
        int N;
        cin >> N;

        unordered_map<int, Node*> nodes;
        unordered_set<int> hasParent;

        for (int i = 0; i < N - 1; i++) {
            int par, child;
            cin >> par >> child;

            if (nodes.find(par) == nodes.end()) nodes[par] = new Node(par);
            if (nodes.find(child) == nodes.end()) nodes[child] = new Node(child);

            nodes[par]->children.push_back(nodes[child]);
            hasParent.insert(child);
        }

        Node* root = nullptr;
        for (auto& it : nodes) {
            if (hasParent.find(it.first) == hasParent.end()) {
                root = it.second;
                break;
            }
        }

        cout << root->countHeight() - 1 << endl;

        for (auto& it : nodes) delete it.second;
    }
    return 0;
}
