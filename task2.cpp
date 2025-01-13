#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    // Constructor to create a new node
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Add element at the end of the list
    void add(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Find a node by value
    Node* find(int value) {
        Node* temp = head;
        while (temp) {
            if (temp->data == value) return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    // Insert F to the left and right of E
    void insertAdjacent(int E, int F) {
        Node* nodeE = find(E);
        if (!nodeE) {
            cout << "Element E not found!" << endl;
            return;
        }

        // Create the new node F
        Node* nodeF = new Node(F);

        // Insert F to the left of E
        nodeF->next = nodeE;
        nodeF->prev = nodeE->prev;
        if (nodeE->prev) {
            nodeE->prev->next = nodeF;
        } else {
            head = nodeF;  // E was the first node
        }
        nodeE->prev = nodeF;

        // Insert F to the right of E
        Node* nodeFRight = new Node(F);
        nodeFRight->prev = nodeE;
        nodeFRight->next = nodeE->next;
        if (nodeE->next) {
            nodeE->next->prev = nodeFRight;
        } else {
            tail = nodeFRight;  // E was the last node
        }
        nodeE->next = nodeFRight;
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to clean up memory
    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

// Main function to test the doubly linked list
int main() {
    DoublyLinkedList list;

    // Add elements to the list
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    cout << "Original List: ";
    list.display();

    // Insert F to the left and right of E (in this case E = 3, F = 99)
    list.insertAdjacent(3, 99);

    cout << "Modified List: ";
    list.display();

    return 0;
}
