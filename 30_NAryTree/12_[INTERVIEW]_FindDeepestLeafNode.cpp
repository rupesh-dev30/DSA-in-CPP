#include <bits/stdc++.h>
using namespace std;

/*
    Logic: DFS karo, depth track karo. Jab bhi leaf mile, check karo kya yeh ab tak ka deepest leaf hai.
*/

class Node {
public:
  int val;
  vector<Node *> children;

  Node(int val) {
    this->val = val;
  }
};

void findDeepest(Node *root, int currentDepth, int &maxDepth, std::vector<int> &deepestNodesValues) {
  if (root == nullptr) {
    return;
  }

  if (root->children.empty()) {
    if (currentDepth > maxDepth) {
      maxDepth = currentDepth;
      deepestNodesValues.clear();
      deepestNodesValues.push_back(root->val);
    } else if (currentDepth == maxDepth) {
      deepestNodesValues.push_back(root->val);
    }
  }

  for (Node *child : root->children) {
    findDeepest(child, currentDepth + 1, maxDepth, deepestNodesValues);
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

  int maxDepth = -1;
  vector<int> deepestNodesValues;
  findDeepest(root, 0, maxDepth, deepestNodesValues);
  cout << "Deepest leaf node: ";
  for (int node : deepestNodesValues) {
    cout << node << " ";
  }
  
  return 0;
}