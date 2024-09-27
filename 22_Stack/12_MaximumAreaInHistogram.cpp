#include <bits/stdc++.h>
using namespace std;

int maxAreaHistogram(vector<int> heights) {
    int n = heights.size();
    vector<int> nextSmallerLeft(n);
    vector<int> nextSmallerRight(n);
    stack<int> s;

    // Next smaller left
    s.push(0);
    nextSmallerLeft[0] = -1;  // First element has no smaller to the left
    for (int i = 1; i < n; i++) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        nextSmallerLeft[i] = (s.empty()) ? -1 : s.top();
        s.push(i);
    }

    // Clear the stack for the next smaller right calculation
    while (!s.empty()) {
        s.pop();
    }

    // Next smaller right
    s.push(n - 1);
    nextSmallerRight[n - 1] = n;  // Last element has no smaller to the right
    for (int i = n - 2; i >= 0; i--) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        nextSmallerRight[i] = (s.empty()) ? n : s.top();
        s.push(i);
    }

    // Calculate maximum area
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = nextSmallerRight[i] - nextSmallerLeft[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << maxAreaHistogram(heights) << endl;

    return 0;
}

/*
  HARD LEVEL QUESTIONS:

    Max Area in Histogram

      Return the area of the largest rectangle in the histogram


      Approach:
        -> NextSmallerRight have no twist

        -> but NextSmallerLeft have some twist, put (n) in last index rather than -1


        Area = height[i] * (left + right - 1)
*/