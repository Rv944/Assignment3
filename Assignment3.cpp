#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    // Insert at the beginning of the list
    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end of the list
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at a specific index (0-indexed)
    void insertAtIndex(int value, int index) {
        if (index < 0) {
            cout << "Invalid index" << endl;
            return;
        }
        if (index == 0) {
            insert(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        int currentIndex = 0;
        while (temp != nullptr && currentIndex < index - 1) {
            temp = temp->next;
            currentIndex++;
        }
        if (temp == nullptr) {
            cout << "Index out of bounds" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete node with a given value
    void deleteNode(int value) {
        Node* temp = head;
        Node* prev = nullptr;
        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Value not found" << endl;
            return;
        }
        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
    }

    // Update value at a given index
    void update(int value, int index) {
        Node* temp = head;
        int currentIndex = 0;
        while (temp != nullptr && currentIndex < index) {
            temp = temp->next;
            currentIndex++;
        }
        if (temp == nullptr) {
            cout << "Index out of bounds" << endl;
            return;
        }
        temp->data = value;
    }

    // Get value at a given index
    int get(int index) {
        Node* temp = head;
        int currentIndex = 0;
        while (temp != nullptr && currentIndex < index) {
            temp = temp->next;
            currentIndex++;
        }
        if (temp == nullptr) {
            cout << "Index out of bounds" << endl;
            return -1; // Return some default value to indicate error
        }
        return temp->data;
    }

    // Print the list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;
    myList.insert(0);
    myList.insert(5);
    myList.insert(10);
    myList.insert(30);
    myList.insert(35);
    myList.insert(40);
    myList.insertAtTail(-5);
    myList.insertAtIndex(20, 3);
    myList.printList();

    cout << "Value at index 2: " << myList.get(2) << endl;

    myList.update(25, 1);
    myList.printList();

    myList.deleteNode(10);
    myList.printList();

    return 0;
}
