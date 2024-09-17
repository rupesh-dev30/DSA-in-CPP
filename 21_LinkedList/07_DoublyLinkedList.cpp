#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Push to the end of the list
    void push_back(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            // List is empty
            head = tail = newNode;
        } else {
            // Add to the end
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Push to the front of the list
    void push_front(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            // List is empty
            head = tail = newNode;
        } else {
            // Add to the front
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Pop from the end of the list
    void pop_back() {
        if (tail == nullptr) {
            cout << "List is empty. Cannot pop from back." << endl;
            return;
        }

        if (head == tail) {
            // Only one element
            delete tail;
            head = tail = nullptr;
        } else {
            // Remove the last element
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }

    // Pop from the front of the list
    void pop_front() {
        if (head == nullptr) {
            cout << "List is empty. Cannot pop from front." << endl;
            return;
        }

        if (head == tail) {
            // Only one element
            delete head;
            head = tail = nullptr;
        } else {
            // Remove the first element
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }

    // Print the list from the beginning
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Print the list from the end
    void printReverse() {
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    // Testing push_back
    dll.push_back(10);
    dll.push_back(20);
    dll.push_back(30);
    dll.printList(); // 10 20 30
    dll.printReverse(); // 30 20 10

    // Testing push_front
    dll.push_front(5);
    dll.push_front(1);
    dll.printList(); // 1 5 10 20 30
    dll.printReverse(); // 30 20 10 5 1

    // Testing pop_back
    dll.pop_back();
    dll.printList(); // 1 5 10 20
    dll.printReverse(); // 20 10 5 1

    // Testing pop_front
    dll.pop_front();
    dll.printList(); // 5 10 20
    dll.printReverse(); // 20 10 5

    return 0;
}
