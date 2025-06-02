#include <bits/stdc++.h>
using namespace std;

struct Node {
  int key;
  Node *left;
  Node *right;
  int height;

  Node(int key) {
    this->key = key;
    left = right = nullptr;
    height = 1;
  }
};

int height(Node *node) {
  return node ? node->height : 0;
}

int getBalance(Node *node) {
  return node ? height(node->left) - height(node->right) : 0;
}

void updateHeight(Node *node) {
  node->height = 1 + max(height(node->left), height(node->right));
}

// ROTATIONS
Node *rightRotate(Node *z) {
  Node *y = z->left;
  Node *T3 = y->right;

  y->right = z;
  z->left = T3;

  updateHeight(z);
  updateHeight(y);

  return y;
}

Node *leftRotate(Node *z) {
  Node *y = z->right;
  Node *T2 = y->left;

  y->left = z;
  z->right = T2;

  updateHeight(z);
  updateHeight(y);

  return y;
}

Node *insert(Node *root, int key) {
  // 1. NORMAL BST INSERTION
  if (root == nullptr)
    return new Node(key);

  if (key < root->key) {
    root->left = insert(root->left, key);
  } else if (key > root->key) {
    root->right = insert(root->right, key);
  } else {
    return root; // Duplicate not allowed
  }

  // 2. Update Height
  updateHeight(root);

  // 3. Get Balance Factor
  int bf = getBalance(root);

  // 4. Balance the tree
  // LL
  if (bf > 1 && key < root->left->key)
    return rightRotate(root);

  // RR
  if (bf < -1 && key > root->right->key)
    return leftRotate(root);

  // LR
  if (bf > 1 && key > root->left->key) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  // RL
  if (bf < -1 && key < root->right->key) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

// Inorder Traversal
void inorder(Node *root) {
  if (!root)
    return;
  inorder(root->left);
  cout << root->key << " ";
  inorder(root->right);
}

int main() {
  Node *root = nullptr;

  int values[] = {10, 20, 30, 40, 50, 25};

  for (int v : values) {
    root = insert(root, v);
  }

  cout << "Inorder of AVL Tree: ";
  inorder(root);
  return 0;
}
