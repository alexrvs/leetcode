class Queue {
    stack<int> a_stack;
    stack<int> b_stack;

public:
    // Push element x to the back of queue.
    void push(int x) {
        a_stack.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (b_stack.size() == 0) {
            while (a_stack.size() != 0) {
                b_stack.push(a_stack.top());
                a_stack.pop();
            }
        }
        b_stack.pop();
    }

    // Get the front element.
    int peek(void) {
        if (b_stack.size() == 0) {
            while (a_stack.size() != 0) {
                b_stack.push(a_stack.top());
                a_stack.pop();
            }
        }
        return b_stack.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (a_stack.size() == 0 && b_stack.size() == 0);
    }
};
