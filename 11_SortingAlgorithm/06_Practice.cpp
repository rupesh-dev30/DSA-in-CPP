#include <bits/stdc++.h>
using namespace std;

// Sort this array of characters using insertion sort in descending order.
void insertionSort(char ch[], int n) {
  for (int i = 1; i < n; i++) {
    char curr = ch[i];
    int prev = i - 1;

    while (prev >= 0 && ch[prev] > curr) {
      swap(ch[prev], ch[prev + 1]);
      prev--;
    }

    ch[prev] = curr;
  }
}

void printChar(char *ch, int n) {
  for (int i = 0; i < n; i++) {
    cout << ch[i] << " ";
  }
  cout << endl;
}

int main() {
  // code here
  char ch[] = {'f', 'b', 'a', 'e', 'c', 'd'};
  int n = sizeof(ch) / sizeof(ch[0]);
  insertionSort(ch, n);

  printChar(ch, n);

  return 0;
}