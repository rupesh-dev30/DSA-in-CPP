#include <bits/stdc++.h>
using namespace std;

/*
           1
          /|\
         / | \
        /  |  \
       2   3   4
      / \      |
     5   6     7

*/

class Node {
public:
  int val;
  vector<Node *> children;

  Node(int val) {
    this->val = val;
  }
};

void preorder(Node *root) {
  if (root == nullptr)
    return;

  // PRINT CURRENT NODE
  cout << root->val << " ";

  // STEP 2: RECURSSIVELY VISIT ALL CHILDREN
  for (Node *child : root->children) {
    preorder(child);
  }
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

  cout << "N-ARY TREE CREATED SUCCESSFULLY" << endl;

  cout << "PREORDER TRAVERSAL: ";
  preorder(root);
  cout << endl;

  return 0;
}