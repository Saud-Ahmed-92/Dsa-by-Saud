#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = NULL;
    
    cout << "Enter numbers to insert into the linked list (enter -1 to stop):\n";

    while (true) {
        Node* ptr = (Node*)malloc(sizeof(Node));
        
        cin >> ptr->data;
        if (ptr->data == -1) {
            free(ptr);
            break;
        }
        ptr->next = NULL;

        if (head == NULL) {
            head = ptr;
        } else {
            Node* curr = head;

            while (curr->next != NULL) {
                curr = curr->next;
            }

            curr->next = ptr;
        }
    }

    cout << "The linked list is: ";
    Node* curr = head;
    
    while (curr != NULL) {
        cout << curr->data<<" ";
        curr = curr->next;
    }
    cout << endl;
    
    int search;
    cout << "Enter the number to search: ";
    cin >> search;
    
    curr = head;
    bool found = false;
    while (curr != NULL) {
        if (curr->data == search) {
            found = true;
            break;
        }
        curr = curr->next;
    }
    if (found) {
        cout << "Value Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }
    return 0;
}

