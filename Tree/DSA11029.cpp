#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

struct Node {
    int data;
    vector<Node*> child; 

    Node(int val) : data(val) {}

    void buildTree(int par, int child_val) {
        if (this->data == par) {
            this->child.push_back(new Node(child_val));
            return;
        }

        for (Node* c : this->child) {
            c->buildTree(par, child_val);
        }
    }

    void rootToLeaves(vector<string>& paths, string path = "1") {
        if (this->child.empty()) { 
            paths.push_back(path);
            return;
        }

        for (Node* node : this->child) {
            node->rootToLeaves(paths, path + " " + to_string(node->data));
        }
    }

    void deleteTree() {
        for (Node* node : this->child) node->deleteTree();
        delete this;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    tests() {
        int N;
        cin >> N;

        Node* root = new Node(1);
        while (--N) {
            int u, v;
            cin >> u >> v;
            root->buildTree(u, v);
        }

        vector<string> paths;
        root->rootToLeaves(paths);
        root->deleteTree();

        sort(paths.begin(), paths.end(), [&] (string str1, string str2) {
            int pos_str1 = str1.find_last_of(" ");
            int pos_str2 = str2.find_last_of(" ");
            return stoi(str1.substr(pos_str1 + 1)) < stoi(str2.substr(pos_str2 + 1));
        });
        for (const string& path : paths) cout << path << endl;
    }
    return 0;
}