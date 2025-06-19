#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

int main() {
    Node* head = NULL;

    cout << "Enter numbers to insert into the doubly linked list (enter -1 to stop):\n";

    while (true) {
        Node* ptr = (Node*)malloc(sizeof(Node));
        cin >> ptr->data;
        if (ptr->data == -1) {
            free(ptr);
            break;
        }
        ptr->next = NULL;
        ptr->prev = NULL;

        if (head == NULL) {
            head = ptr;
        } else {
            Node* curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = ptr;
            ptr->prev = curr;
        }
    }

    cout << "The doubly linked list is: ";
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data;
        if (curr->next != NULL)
            cout << ", ";
        curr = curr->next;
    }
    cout << endl;

    int del;
    cout << "Enter the number you want to delete: ";
    cin >> del;

    if (head == NULL) {
        cout << "List is empty";
    } else if (head->data == del) {
        Node* temp = head;
        head = head->next;
        free(temp);
    } else {
        curr = head->next;
        Node* prev = head;

        while (curr != NULL) {
            if (curr->data == del) {
                prev->next = curr->next;
                free(curr);
                break;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    cout << "The updated linked list is: ";
    curr = head;

    while (curr != NULL) {
        cout << curr->data;
        if (curr->next != NULL) cout << ", ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}

