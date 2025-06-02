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

void serialize(Node *root, vector<int> &data) {
  if (root == nullptr)
    return;

  data.push_back(root->val);
  data.push_back(root->children.size());

  for (Node *child : root->children) {
    serialize(child, data);
  }
}

Node *deserialize(vector<int> &data, int &index) {
  if (index >= data.size())
    return nullptr;

  Node *node = new Node(data[index++]);
  int childrenCnt = data[index++];

  for (int i = 0; i < childrenCnt; i++) {
    node->children.push_back(deserialize(data, index));
  }
  return node;
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

bool isSameTree(Node *r1, Node *r2) {
  if (!r1 && !r2)
    return true;

  if (!r1 || !r2 || r1->val != r2->val || r1->children.size() != r2->children.size())
    return false;

  for (int i = 0; i < r1->children.size(); i++) {
    if (!isSameTree(r1->children[i], r2->children[i]))
      return false;
  }

  return true;
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



  return 0;
}