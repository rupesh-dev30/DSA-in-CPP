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

int diameter = 0;

int findHeight(Node *root) {
  if (root == nullptr)
    return 0;

  int max1 = 0, max2 = 0;

  for (Node *child : root->children) {
    int h = findHeight(child);

    if (h > max1) {
      max2 = max1;
      max1 = h;
    } else if (h > max2) {
      max2 = h;
    }
  }

  diameter = max(diameter, max1 + max2); // max path through current node
  return max1 + 1;
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

  diameter = 0;
  findHeight(root);
  cout << "Diameter of the tree: " << diameter << endl;

  return 0;
}