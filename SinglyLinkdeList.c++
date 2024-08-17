#include <iostream>

// Define a node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node*& head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}
// Function to insert a node at the end of the list
void insertAtEnd(Node*& head, int data) {
    Node* newNode = createNode(data);
    // If the list is empty, the new node becomes the head
    if (head == nullptr) {
        head = newNode;
        return;
    }
    // Otherwise, find the last node
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    // Link the new node to the end of the list
    current->next = newNode;
}

void insertAfterPosition(Node*& head, int position, int data) {
    if (position <= 0) {
        std::cout << "Invalid position. Position should be greater than 0." << std::endl;
        return;
    }

    Node* newNode = createNode(data);
    Node* current = head;
    int currentPosition = 1;

    while (current != nullptr && currentPosition < position) {
        current = current->next;
        currentPosition++;
    }

    if (current == nullptr) {
        std::cout << "Position exceeds the length of the list. Inserting at the end." << std::endl;
        insertAtEnd(head, data);
    } else {
        newNode->next = current->next;
        current->next = newNode;
    }
}
// Function to display the linked list
void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    Node* head = nullptr; // Initialize an empty list

    // Insert some nodes at the beginning
    insertAtBeginning(head, 3);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 1);

    std::cout << "Linked List after inserting nodes at the beginning:" << std::endl;
    displayList(head);

    // Insert nodes at the end
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    std::cout << "Linked List after inserting nodes at the end:" << std::endl;
    displayList(head);

    // Insert node after position 2
    insertAfterPosition(head, 2, 10);

    std::cout << "Linked List after inserting node after position 2:" << std::endl;
    displayList(head);

    // Insert node after position 5 (last node)
    insertAfterPosition(head, 5, 20);

    std::cout << "Linked List after inserting node after position 5:" << std::endl;
    displayList(head);

    // Insert node after position 7 (non-existent position)
    insertAfterPosition(head, 7, 30);

    std::cout << "Linked List after inserting node after position 7:" << std::endl;
    displayList(head);

    return 0;
}

/* output
Linked List after inserting nodes at the beginning:
1 -> 2 -> 3 -> nullptr
Linked List after inserting nodes at the end:
1 -> 2 -> 3 -> 4 -> 5 -> nullptr
Linked List after inserting node after position 2:
1 -> 2 -> 10 -> 3 -> 4 -> 5 -> nullptr
Linked List after inserting node after position 5:
1 -> 2 -> 10 -> 3 -> 4 -> 5 -> 20 -> nullptr
Position exceeds the length of the list. Inserting at the end.
Linked List after inserting node after position 7:
1 -> 2 -> 10 -> 3 -> 4 -> 5 -> 20 -> nullptr
*/