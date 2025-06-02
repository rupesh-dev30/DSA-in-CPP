#include <bits/stdc++.h>
using namespace std;

/*
    Tree ko ek string mein convert karna (serialize), aur string se wapas tree banana (deserialize)

    Serialization Format:

    - Example Tree:

        1 [2 [5] 3 4 [6 7]]

        Serialized string: "1 3 2 1 5 0 3 0 4 2 6 0 7 0"


*/

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

  vector<int> data;
  serialize(root, data);

  cout << "Serialized Tree: ";
  for (int x : data)
    cout << x << " ";
  cout << endl;

  // Deserialize
  int idx = 0;
  Node *newRoot = deserialize(data, idx);
  cout << "Level order of deserialized tree:\n";
  levelOrder(newRoot);

  return 0;
}