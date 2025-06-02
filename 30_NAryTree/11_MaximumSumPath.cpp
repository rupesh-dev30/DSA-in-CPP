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

void maxSumPath(Node *root, int currentSum, int &maxSum) {
  if (root == nullptr)
    return;

  currentSum += root->val;

  if (root->children.empty()) {
    maxSum = max(maxSum, currentSum);
  }

  for (Node *child : root->children) {
    maxSumPath(child, currentSum, maxSum);
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

  int maxSum = 0;
  maxSumPath(root, 0, maxSum);
  cout << "Maximum Sum Path from root to leaf: " << maxSum << endl;

  return 0;
}