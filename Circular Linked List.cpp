#include <iostream>
#include <stdlib.h> 
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = NULL; // Head

    cout << "Enter numbers to insert into the circular linked list (enter -1 to stop):\n";

    while (true) {
        Node* ptr = (Node*)malloc(sizeof(Node));
        cin >> ptr->data;

        if (ptr->data == -1) {
            free(ptr);
            break;
        }

        ptr->next = NULL;

        if (head == NULL) {  // First node
            head = ptr;
            head->next = head;  // Circular link
        } else {
            Node* curr = head;
            while (curr->next != head) { // Find last node
                curr = curr->next;
            }
            curr->next = ptr;
            ptr->next = head; //move to next
        }
    }

    // Display the circular linked list
    if (head != NULL) {
        cout << "The circular linked list is: ";
        Node* curr = head;
        do {
            cout << curr->data;
            if (curr->next != head) cout << ", ";
            curr = curr->next;
        } while (curr != head);
        cout << endl;
    }

    // Searching an element
    int search;
    cout << "Enter the number to search: ";
    cin >> search;
    Node* curr = head;
    bool found = false;

    if (head != NULL) {
        do {
            if (curr->data == search) {
                found = true;
                break;
            }
            curr = curr->next;
        } while (curr != head);
    }

    if (found) cout << "Value Found\n";
    else cout << "Not Found\n";

}
