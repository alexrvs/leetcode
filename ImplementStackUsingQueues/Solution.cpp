class Stack {
public:
    queue<int> qa;
    queue<int> qb;
    int mark = 0;
    // Push element x onto stack.
    void push(int x) {
        if (mark == 0) {
            qa.push(x);
        } else {
            qb.push(x);
        }
        return;
    }

    // Removes the element on top of the stack.
    void pop() {
        if (mark == 0) {
            shift(qa, qb);
            qa.pop();
            mark = 1;
        } else {
            shift(qb, qa);
            qb.pop();
            mark = 0;
        }
        return;
    }
    
    void shift(queue<int>& from, queue<int>& to) {
        while (from.size() > 1) {
            to.push(from.front());
            from.pop();
        }
    }

    // Get the top element.
    int top() {
        if (mark == 0) {
            shift(qa, qb);
            return qa.front();
        } else {
            shift(qb, qa);
            return qb.front();
        }
    }

    // Return whether the stack is empty.
    bool empty() {
        return qa.empty() && qb.empty();
    }
};