#include <bits/stdc++.h>
using namespace std;

void nextGreater(vector<int> arr, vector<int> &ans) {
    stack<int> s;
    int n = arr.size();
    
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        
        if (s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> ans(arr.size());

    nextGreater(arr, ans);

    return 0;
}

/*
    NEXT GREATER: First greater element that is to the right.

    arr = [6, 8, 0, 1, 3]
    ans = [8, -1, 1, 3, -1]
*/
