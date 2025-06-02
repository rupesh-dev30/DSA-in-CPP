#include <bits/stdc++.h>
using namespace std;

struct Node {
  int key;
  Node *left;
  Node *right;
  int height;

  Node(int k) {
    key = k;
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

void updatedHeight(Node *node) {
  node->height = 1 + max(height(node->left), height(node->right));
}

int main() {
  // code here

  return 0;
}