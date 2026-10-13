#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a node
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    // Constructor to initialize an empty list
    LinkedList() {
        head = nullptr;
    }

    // 1. Insert at Beginning
    void insert_at_beginning(int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    // 2. Insert at End
    void insert_at_end(int data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }

    // 3. Insert at Specific Position (0-indexed)
    void insert_at_position(int pos, int data) {
        if (pos == 0) {
            insert_at_beginning(data);
            return;
        }
        Node* new_node = new Node(data);
        Node* current = head;
        for (int i = 0; i < pos - 1; i++) {
            if (current == nullptr) {
                cout << "Position out of bounds\n";
                delete new_node; // Prevent memory leak
                return;
            }
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Position out of bounds\n";
            delete new_node;
            return;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

    // 4. Delete at Beginning
    void delete_at_beginning() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;       // Hold the node to delete
        head = head->next;       // Move head forward
        delete temp;             // Free memory
    }

    // 5. Delete at End
    void delete_at_end() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;    // Free memory of last node
        current->next = nullptr;
    }

    // 6. Delete at Specific Position
    void delete_at_position(int pos) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        if (pos == 0) {
            delete_at_beginning();
            return;
        }
        Node* current = head;
        for (int i = 0; i < pos - 1; i++) {
            if (current == nullptr || current->next == nullptr) {
                cout << "Position out of bounds\n";
                return;
            }
            current = current->next;
        }
        if (current->next == nullptr) {
            cout << "Position out of bounds\n";
            return;
        }
        Node* temp = current->next;    // Node to be deleted
        current->next = current->next->next; // Bypass it
        delete temp;                   // Free memory
    }

    // Helper function to print the list
    void display() {
        Node* current = head;
        if (current == nullptr) {
            cout << "List is empty\n";
            return;
        }
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) cout << " -> ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList llist;

    llist.insert_at_end(10);       // List: 10
    llist.insert_at_end(30);       // List: 10 -> 30
    llist.insert_at_beginning(5);  // List: 5 -> 10 -> 30
    llist.insert_at_position(1, 7);// List: 5 -> 7 -> 10 -> 30

    cout << "Current List: ";
    llist.display();               // Output: 5 -> 7 -> 10 -> 30

    llist.delete_at_beginning();   // Removes 5
    llist.delete_at_end();         // Removes 30
    //llist.delete_at_position(1);   // Removes 10 (at index 1)

    cout << "After Deletions: ";
    llist.display();               // Output: 7

    return 0;
}