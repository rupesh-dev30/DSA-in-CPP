#include <bits/stdc++.h>
using namespace std;

/*
    LCA (Lowest Common Ancestor) in N-ary Tree

      Do nodes u and v ka Lowest Common Ancestor wo lowest node hoti hai jisse dono nodes descend karte hain.

    Approach:
      Dono nodes ke path find karo root se.
      Dono paths ko compare karo.
      Last common node hi LCA hoti hai.
*/

class Node {
public:
  int val;
  vector<Node *> children;

  Node(int val) {
    this->val = val;
  }
};

bool getPath(Node *root, int target, vector<int> &path) {
  if (root == nullptr)
    return false;

  path.push_back(root->val);

  if (root->val == target)
    return true;

  for (Node *child : root->children) {
    if (getPath(child, target, path))
      return true;
  }

  // Backtrack if not found in this path
  path.pop_back();
  return false;
}

Node *LCA(Node *root, int val1, int val2) {
  vector<int> path1, path2;

  if (!getPath(root, val1, path1) || !getPath(root, val2, path2)) {
    return nullptr; // One of the nodes not found
  }

  int i = 0;
  while (i < path1.size() && i < path2.size() && path1[i] == path2[i])
    i++;

  return new Node(path1[i - 1]); // common node till last match
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

  int a, b;
  cout << "Enter two values to find LCA: ";
  cin >> a >> b;
  Node *lca = LCA(root, a, b);
  if (lca)
    cout << "LCA: " << lca->val << endl;
  else
    cout << "One or both nodes not found!" << endl;

  return 0;
}