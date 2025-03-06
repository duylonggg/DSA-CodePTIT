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

void deleteAllOccurrences(Node*& head, int x) {
    while (head && head->data == x) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* current = head;
    while (current && current->next) {
        if (current->next->data == x) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        } else {
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
    int n, x;
    cin >> n;

    Node* first = nullptr;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertTail(first, value);
    }

    cin >> x;
    
    deleteAllOccurrences(first, x);
    
    printList(first);

    return 0;
}
