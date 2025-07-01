#include <iostream>
using namespace std;

void deleteNode(Node *&head, int value) {
    Node *curr = head;
    Node *prev = nullptr;

    while (curr) {
        if (curr->data == value) {
            if (prev == nullptr) { // Deleting the head
                head = curr->next;
            } else { // Deleting non-head node
                prev->next = curr->next;
            }
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
}