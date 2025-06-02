#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  vector<Node *> children;

  Node(int val) {
    this->val = val;
  }
};

int countNodes(Node *root) {
  if (root == nullptr)
    return 0;

  int count = 1;
  for (Node *child : root->children) {
    count += countNodes(child);
  }
  return count;
}

int countLeafNodes(Node *root) {
  if (root == nullptr)
    return 0;

  if (root->children.size() == 0)
    return 1;

  int count = 0;
  for (Node *child : root->children) {
    count += countLeafNodes(child);
  }
  return count;
}

int main() {
  // code here
  Node *root = new Node(1);

  // CHILDREN OF ROOT
  Node *child1 = new Node(2);
  Node *child2 = new Node(3);
  Node *child3 = new Node(4);

  root->children.push_back(child1);
  root->children.push_back(child2);
  root->children.push_back(child3);

  // CHILDREN OF CHILD1
  Node *child1a = new Node(5);
  Node *child1b = new Node(6);

  child1->children.push_back(child1a);
  child1->children.push_back(child1b);

  // CHILD OF CHILD3
  Node *child3a = new Node(7);
  child3->children.push_back(child3a);

  cout << "TOTAL COUNT OF NODES : " << countNodes(root) << endl;
  cout << "TOTAL COUNT OF LEAF NODES : " << countLeafNodes(root) << endl;

  return 0;
}