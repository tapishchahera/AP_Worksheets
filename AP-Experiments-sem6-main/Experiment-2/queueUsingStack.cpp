/*
 Implement a FIFO queue using two stacks. The queue should support all the 
 functions of a normal queue: push, peek, pop, and empty.
*/

// Time Complexity: O(1) for push, O(n) for pop and peek
// Space Complexity: O(n) for the two stacks

#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> in_stack, out_stack;

    void transfer() {
        while (!in_stack.empty()) {
            out_stack.push(in_stack.top());
            in_stack.pop();
        }
    }
    
public:
    MyQueue() {}

    void push(int x) {
        in_stack.push(x);
    }

    int pop() {
        if (out_stack.empty()) {
            transfer();
        }
        int topElement = out_stack.top();
        out_stack.pop();
        return topElement;
    }

    int peek() {
        if (out_stack.empty()) {
            transfer();
        }
        return out_stack.top();
    }

    bool empty() {
        return in_stack.empty() && out_stack.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.peek() << endl; // 1
    cout << q.pop() << endl; // 1
    cout << q.empty() << endl; // 0
    cout << q.pop() << endl; // 2
    cout << q.pop() << endl; // 3
    cout << q.empty() << endl; // 1
    return 0;
}