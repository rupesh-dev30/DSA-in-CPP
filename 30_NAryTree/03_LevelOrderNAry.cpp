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

Node *buildTree() {
  int rootVal;
  cout << "Enter root node value: ";
  cin >> rootVal;

  Node *root = new Node(rootVal);
  queue<Node *> q;
  q.push(root);

  while (!q.empty()) {
    Node *current = q.front();
    q.pop();

    int numChildren;
    cout << "Enter number of children of node " << current->val << ": ";
    cin >> numChildren;

    for (int i = 0; i < numChildren; i++) {
      int childVal;
      cout << "Enter value of child " << (i + 1) << " of node " << current->val << ": ";

      cin >> childVal;

      Node *child = new Node(childVal);
      current->children.push_back(child);
      q.push(child);
    }
  }

  return root;
}

void levelOrder(Node *root) {
  if (root == nullptr)
    return;

  queue<Node *> q;
  q.push(root);

  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      Node *current = q.front();
      q.pop();
      cout << current->val << " ";

      for (Node *child : current->children) {
        q.push(child);
      }
    }
    cout << endl; // NEXT LEVEL
  }
}

int main() {
  // code here
  Node *root = buildTree();

  cout << "\nLEVEL ORDER TRAVERSAL: \n";
  levelOrder(root);

  return 0;
}