#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

void insertTail(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void removeDuplicates(Node*& head) {
    if (!head) return;

    unordered_set<int> seen;
    Node* current = head;
    seen.insert(current->data);

    while (current->next) {
        if (seen.find(current->next->data) != seen.end()) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        } else {
            seen.insert(current->next->data);
            current = current->next;
        }
    }
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Node* first = nullptr;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertTail(first, value);
    }

    removeDuplicates(first);
    printList(first);

    return 0;
}
