#include <bits/stdc++.h>
using namespace std;

/*
    Building the Heap Data Structure

      1. PUSH()  // Insert O(logn)
      2. POP()   // Pop max or min  O(logn)
      3. Top()   // get max or min  O(1)

      NOTE: Heap is not implemented as a class because of large time complexity

      HEAP: Parent child relationship helps to build.

                    9(0)
                    / \
                   /   \
                 4(1)  5(2)
                 / \
                /   \
              1(3)  2(4)


        INDEX  :   0  1  2  3  4
        VECTOR : [ 8  4  5  1  2 ]


    If index i(parent index) then its child index are
        left child index = 2 * i + 1
        right child index = 2 * i + 2

    if child index = x
        then parent index = (x - 1)/2


    NOTE: If heap is implemented as 1 based indexing then
            parent index = i
            left child index = 2 * i
            right child index = 2 * i + 1

            child index = x
            then parent index = x/2

*/

class Heap {
  vector<int> v; // CBT

  /*
      Heapify function O(logN)
        it take the index = 0 where it get 3 value
          1. Parent Val1 = i
          2. Left Child Val2 = 2 * i + 1
          3. Right Child Val3 = 2 * i + 2

          maxiValueIndex = max(Val1,Val2,Val3);
          swap(maxValueIndex, i)
          heapify(maxValueIndex)
  */

  void heapify(int index) {
    if (index >= v.size()) {
      return;
    }

    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;

    int maxIndex = index;
    if (leftIndex < v.size() && v[leftIndex] > v[maxIndex]) {
      maxIndex = leftIndex;
    }
    if (rightIndex < v.size() && v[rightIndex] > v[maxIndex]) {
      maxIndex = rightIndex;
    }

    swap(v[index], v[maxIndex]);
    if (maxIndex != index) { // Swapping with child node
      heapify(maxIndex);
    }
  }

public:
  void push(int val) {
    // Step 1: Push
    v.push_back(val); // O(1)

    // Step 2: Fix the heap
    int childIndexX = v.size() - 1;
    int parentIndex = (childIndexX - 1) / 2;

    /*
    // MIN Heap
    while (parentIndex >= 0 && v[childIndexX] < v[parentIndex]) { // O(logN)

      swap(v[childIndexX], v[parentIndex]);
      childIndexX = parentIndex;
      parentIndex = (childIndexX - 1) / 2;
    }

    */

    // MAX heap
    while (parentIndex >= 0 && v[childIndexX] > v[parentIndex]) { // O(logN)
      swap(v[childIndexX], v[parentIndex]);
      childIndexX = parentIndex;
      parentIndex = (childIndexX - 1) / 2;
    }
  }

  void pop() { // O(1) + O(1) + O(logN) = O(logN)
    // 3 Step process

    // Step 1: Swap root value with the last element  // O(1)
    swap(v[0], v[v.size() - 1]);

    // Step 2: Delete the lastIndex  // O(1)
    v.pop_back();

    // Step 3: Fix the heap  // O(logN)
    heapify(0);
  }

  int top() {           // O(1)
    if (v.size() > 0) { // Highest Priority Element
      return v[0];
    } else {
      return -1;
    }
  }

  bool empty() { // O(1)
    return v.size() == 0;
  }
};

int main() {
  // code here
  Heap heap;
  heap.push(50);
  heap.push(10);
  heap.push(100);
  heap.push(20);

  while (!heap.empty()) {
    cout << heap.top() << " ";
    heap.pop();
  }

  return 0;
}