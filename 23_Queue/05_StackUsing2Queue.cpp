#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    // Push element into the stack
    void push(int data) {
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Push the new element to q1
        q1.push(data);

        // Move all elements back to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    // Pop the top element of the stack
    void pop() {
        if (!q1.empty()) {
            q1.pop();
        }
    }

    // Get the top element of the stack
    int top() {
        if (!q1.empty()) {
            return q1.front();
        }
        return -1;  // Return an invalid value if the stack is empty
    }

    // Check if the stack is empty
    bool empty() {
        return q1.empty();
    }
};

int main() {
    // Example usage of the stack
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    // Print and pop elements from the stack
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
