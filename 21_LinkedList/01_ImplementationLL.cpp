#include <bits/stdc++.h>
using namespace std;

// Node class representing each element of the linked list
class Node {
public:
  int data; // Value stored in the node
  Node *next; // Pointer to the next node in the list

  // Constructor to initialize a node with the given data
  Node(int data) {
    // Initialize the node with the given value and set the next pointer to NULL
    this->data = data;
    this->next = NULL;
  }

  // Destructor to handle the deletion of the node
  ~Node() {
    // If the current node has a next node, delete it to avoid memory leaks
    if (this->next != NULL) {
      delete this->next;
      this->next = NULL;
    }
  }
};

// List class representing a singly linked list
class List {
  Node *head; // Pointer to the first node in the list
  Node *tail; // Pointer to the last node in the list

public:
  // Constructor to initialize an empty list
  List() {
    head = NULL; // Head is initially NULL since the list is empty
    tail = NULL; // Tail is also NULL
  }

  // Destructor to delete the entire list when the object is destroyed
  ~List() {
    if (head != NULL) {
      delete head; // Delete all nodes starting from the head
      head = NULL;
    }
  }

  // Function to print all elements of the list
  void printL() {
    Node *temp = head; // Start from the head node

    // Traverse the list and print each node's data
    while (temp != NULL) {
      cout << temp->data << "->";
      temp = temp->next;
    }
    cout << "NULL" << endl; // Indicate the end of the list
  }

  // Function to add a new node with 'data' at the front of the list
  void push_front(int data) {
    Node *newNode = new Node(data); // Dynamically create a new node
    if (head == NULL) {
      head = tail = newNode; // If the list is empty, head and tail point to the new node
    } else {
      newNode->next = head; // Make the new node point to the current head
      head = newNode; // Update head to the new node
    }
  }

  // Function to add a new node with 'data' at the end of the list
  void push_back(int data) {
    Node *newNode = new Node(data); // Dynamically create a new node
    if (head == NULL) {
      head = tail = new Node(data); // If list is empty, new node becomes head and tail
    } else {
      tail->next = newNode; // Link the current tail to the new node
      tail = newNode; // Update tail to the new node
    }
  }

  // Function to insert a new node with 'data' at position 'pos'
  void insert(int data, int pos) {
    Node *newNode = new Node(data); // Create a new node

    Node *temp = head; // Start from the head
    for (int i = 0; i < pos - 2; i++) {
      if (temp == NULL) {
        cout << "Position out of range" << endl;
        return;
      }
      temp = temp->next; // Move to the next node until reaching the insertion point
    }

    // Insert the new node at the correct position
    newNode->next = temp->next;
    temp->next = newNode;
  }

  // Function to remove the node at the front of the list
  void pop_front() {
    if (head == NULL) {
      cout << "List is empty" << endl;
      return;
    }

    Node *temp = head; // Store the current head
    head = head->next; // Update head to the next node

    temp->next = NULL; // Isolate the old head
    delete temp; // Delete the old head
  }

  // Function to remove the node at the end of the list
  void pop_back() {
    if (head == NULL) {
      cout << "List is empty" << endl;
      return;
    }

    Node *temp = head;
    // Traverse the list to find the second last node
    while (temp->next != tail) {
      temp = temp->next;
    }

    temp->next = NULL; // Set the second last node's next to NULL
    delete tail; // Delete the current tail
    tail = temp; // Update tail to the second last node
  }

  // Function to search for a key in the list and return its position
  int search(int key) {
    Node *temp = head;
    int position = 0;

    // Traverse the list to find the key
    while (temp != NULL) {
      if (temp->data == key) {
        return position; // Return the position if key is found
      } else {
        temp = temp->next; // Move to the next node
        position++;
      }
    }
    return -1; // Return -1 if key is not found
  }

  // Helper function for recursive search
  int helper(Node *temp, int key) {
    if (temp == NULL) {
      return -1; // Base case: if node is NULL, return -1 (not found)
    }

    if (temp->data == key) {
      return 0; // If key is found, return 0
    }

    int position = helper(temp->next, key); // Recursive call to the next node
    if (position == -1) {
      return -1; // Return -1 if key is not found in subsequent nodes
    }

    return position + 1; // Increment the position as we backtrack
  }

  // Function to search for a key using recursion
  int searchRecursively(int key) {
    return helper(head, key); // Call helper function starting from the head
  }

  // Function to reverse the linked list
  void reverse() {
    Node *curr = head;
    Node *prev = NULL;

    // Traverse the list and reverse the links between nodes
    while (curr != NULL) {
      Node *next = curr->next;
      curr->next = prev; // Reverse the link

      prev = curr; // Move prev and curr one step forward
      curr = next;
    }

    head = prev; // Update head to the new first node (previously tail)
  }

  // Function to get the size of the list
  int getSize() {
    int size = 0;
    Node* temp = head;

    // Traverse the list and count the nodes
    while(temp != NULL) {
      temp = temp->next;
      size++;
    }
    return size;
  }

  // Function to remove the Nth node from the end
  void removeNth(int pos) {
    int size = getSize(); // Get the total size of the list
    Node *prev = head;
    
    // Traverse to the (size - pos)th node
    for (int i = 1; i < (size - pos); i++) {
      prev = prev->next;
    }

    // Remove the target node
    Node *toDel = prev->next;
    cout << "Going to delete: " << toDel->data << endl;
    prev->next = prev->next->next; // Bypass the node to be deleted
  }
};

// Main function to demonstrate the linked list operations
int main() {
  List ll;
  ll.push_front(3); // Add 3 to the front
  ll.push_front(2); // Add 2 to the front
  ll.push_front(1); // Add 1 to the front
  ll.push_back(4);  // Add 4 to the back
  ll.push_back(5);  // Add 5 to the back
  ll.push_back(6);  // Add 6 to the back
  ll.push_back(7);  // Add 7 to the back
  ll.push_back(8);  // Add 8 to the back

  ll.insert(20, 3); // Insert 20 at position 3

  ll.pop_front(); // Remove the front node
  ll.pop_back();  // Remove the back node
  cout << ll.search(6) << endl; // Search for the key 6
  cout << ll.searchRecursively(6) << endl; // Search recursively for key 6
  ll.printL(); // Print the list
  ll.reverse(); // Reverse the list
  ll.printL(); // Print the reversed list

  ll.removeNth(6); // Remove the 6th node from the end
  ll.printL(); // Print the list after removal

  return 0;
}
