#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(string &s, int &index) {
  if (index >= s.length() || s[index] == ')') {
    return NULL;
  }

  // Extract number
  string num = "";
  while (index < s.length() && (isdigit(s[index]) || s[index] == '-')) {
    num += s[index];
    index++;
  }

  if (num.empty())
    return NULL;

  TreeNode *root = new TreeNode(stoi(num));

  // Check left subtree
  if (index < s.length() && s[index] == '(') {
    index++;
    root->left = buildTree(s, index);
    index++;
  }

  // Check right subtree
  if (index < s.length() && s[index] == '(') {
    index++;
    root->right = buildTree(s, index);
    index++;
  }

  return root;
}

int kthLevel(TreeNode *root, int k) {
  if (!root)
    return 0;

  queue<pair<TreeNode *, int>> q;
  q.push({root, 0});
  int sum = 0;

  while (!q.empty()) {
    TreeNode *node = q.front().first;
    int level = q.front().second;
    q.pop();

    if (level == k) {
      sum += node->val;
    }

    if (node->left)
      q.push({node->left, level + 1});
    if (node->right)
      q.push({node->right, level + 1});
  }
  return sum;
}

void deleteTree(TreeNode *root) {
  if (!root)
    return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

int main() {
  int k;
  string treeStr;

  // Read input
  cin >> k;
  cin.ignore();
  getline(cin, treeStr);

  int index = 0;
  TreeNode *root = buildTree(treeStr, index);

  // Compute and print the sum at Kth level
  cout << kthLevel(root, k) << endl;

  // Free memory
  deleteTree(root);

  return 0;
}