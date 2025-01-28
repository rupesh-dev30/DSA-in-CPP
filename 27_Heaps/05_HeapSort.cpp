#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i) {
    while (true) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int maxIndex = i;

        if (leftChild < n && arr[leftChild] > arr[maxIndex]) {
            maxIndex = leftChild;
        }
        if (rightChild < n && arr[rightChild] > arr[maxIndex]) {
            maxIndex = rightChild;
        }
        if (maxIndex != i) {
            swap(arr[i], arr[maxIndex]);
            i = maxIndex;  // Move down the heap
        } else {
            break;  // Heap property is satisfied
        }
    }
}

void heapSort(vector<int> &arr) {
    int n = arr.size();

    // Step 1: Build MaxHeap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Step 2: Sorting by extracting the max element
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Move max element to end
        heapify(arr, i, 0);     // Heapify the reduced heap
    }
}

int main() {
    vector<int> arr = {1, 4, 2, 5, 3};

    heapSort(arr);

    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
