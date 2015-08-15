class MinStack {
public:
    vector<int> elements;
    vector<int> minIndexes;
    void push(int x) {
        if (elements.size() == 0) {
            elements.push_back(x);
            minIndexes.push_back(0);
        } else {
            elements.push_back(x);
            if (x < elements[minIndexes.back()]) {
                minIndexes.push_back(elements.size()-1);
            }
        }
    }

    void pop() {
        if (minIndexes.back() == elements.size()-1) {
            minIndexes.pop_back();
        }
        elements.pop_back();
    }

    int top() {
        return elements.back();
    }

    int getMin() {
        return elements[minIndexes.back()];
    }
};
