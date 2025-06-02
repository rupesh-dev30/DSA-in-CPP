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

void printAllPaths(Node *root, vector<int> &path) {
  if (root == nullptr)
    return;

  path.push_back(root->val);

  if (root->children.empty()) {
    for (int val : path)
      cout << val << " ";
    cout << endl;
  }

  for (Node *child : root->children) {
    printAllPaths(child, path);
  }

  path.pop_back();
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

  vector<int> path;
  cout << "All Root-to-Leaf Paths:\n";
  printAllPaths(root, path);

  return 0;
}