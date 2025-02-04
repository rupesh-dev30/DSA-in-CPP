/*
  This program implements a Hash Table using Separate Chaining for collision handling. The HashTable class maintains an array of linked lists (chaining method) to store key-value pairs. If a collision occurs (i.e., multiple keys map to the same index), the key-value pair is inserted at the beginning of the linked list.
*/

/*
    +--------------------------+
    |    Key     |     Value   |
    |--------------------------|
    |   India    |     150     |
    |--------------------------|
    |   China    |     150     |
    |--------------------------|
    |   USA      |     120     |
    |--------------------------|
    |   Nepal    |     10      |
    +--------------------------+
*/

#include <bits/stdc++.h>
using namespace std;

// The Node class represents an individual entry in the hash table.
class Node {
public:
  string key;
  int value;
  Node *next;

  // Constructor: Initializes the key, value, and sets next to NULL.
  Node(string key, int value) {
    this->key = key;
    this->value = value;
    next = NULL;
  }

  // Destructor: Recursively deletes all linked nodes to avoid memory leaks.
  ~Node() {
    if (next != NULL) {
      delete next;
    }
  }
};

class HashTable {
  int totalSize; // Total size of the hash table (number of buckets)
  int currSize;  // Current number of elements inserted
  Node **table;  // Array of pointers (each index points to a linked list)

  int hashFunction(string key) {
    int index = 0;
    for (int i = 0; i < key.length(); i++) {
      index = (index + (key[i] * key[i])) % totalSize;
    }
    return index;
  }

  void rehash() {
    Node **oldTable = table;
    int oldSize = totalSize;

    totalSize = 2 * totalSize; // Double the table size
    currSize = 0;
    table = new Node *[totalSize];

    for (int i = 0; i < totalSize; i++) {
      table[i] = NULL;
    }

    for (int i = 0; i < oldSize; i++) {
      Node *temp = oldTable[i];
      while (temp != NULL) {
        insert(temp->key, temp->value);
        temp = temp->next;
      }

      if (oldTable[i] != NULL) {
        delete oldTable[i];
      }
    }
    delete[] oldTable;
  }

public:
  HashTable(int size = 5) {
    totalSize = size;
    currSize = 0;
    table = new Node *[totalSize];

    for (int i = 0; i < totalSize; i++) {
      table[i] = NULL;
    }
  }

  void insert(string key, int val) {
    int index = hashFunction(key);

    Node *newNode = new Node(key, val);
    Node *head = table[index];

    newNode->next = table[index];
    table[index] = newNode;
    currSize++;

    double lambda = currSize / (double)totalSize;

    if (lambda > 1) {
      rehash();
    }
  }

  bool exists(string key) {
    int index = hashFunction(key);
    Node *temp = table[index];
    while (temp != NULL) {
      if (temp->key == key) {
        return true;
      }
      temp = temp->next;
    }
    return false;
  }

  int search(string key) {
    int index = hashFunction(key);
    Node *temp = table[index];
    while (temp != NULL) {
      if (temp->key == key) {
        return temp->value;
      }
      temp = temp->next;
    }
    return -1;
  }

  void print() {
    for (int i = 0; i < totalSize; i++) {
      cout << "index " << i << "->";
      Node *temp = table[i];
      while (temp != NULL) {
        cout << "(" << temp->key << "," << temp->value << ")->";
        temp = temp->next;
      }
      cout << "NULL" << endl;
    }
  }

  void remove(string key) {
    int index = hashFunction(key);

    Node *temp = table[index];
    Node *prev = temp;
    while (temp != NULL) {
      if (temp->key == key) {
        if (prev == temp) {
          table[index] = temp->next;
        } else {
          prev->next = temp->next;
        }
        break;
      }

      prev = temp;
      temp = temp->next;
    }
  }
};

int main() {
  // int *table;
  // table = new int[size];
  HashTable ht;

  ht.insert("India", 150);
  ht.insert("China", 150);
  ht.insert("US", 50);
  ht.insert("Nepal", 10);
  ht.insert("UK", 20);

  if (ht.exists("India")) {
    cout << "India exists : " << ht.search("India") << endl;
  }

  ht.print();

  ht.remove("US");

  cout << endl;
  ht.print();

  return 0;
}