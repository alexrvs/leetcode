/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
private:
    vector<NestedInteger> elems;

    NestedInteger helper(string& s, int start, int end) {
        NestedInteger ni;
        int nestedStart = -1;
        int n = 0;
        int num = 0;
        if (s[start] != '[') {
            bool neg = false;
            for (int i = start; i <= end; i++) {
                if (s[i] == '-') {
                    neg = true;
                } else {
                    num = 10 * num + (s[i] - '0');
                }
            }
            if (neg == true) num *= -1;
            ni.setInteger(num);
        } else {
            start++;
            end--;
            int lastStart = start;
            for (int i = start ; i <= end; i++) {
                if (s[i] == '[') {
                    n++;
                    if (nestedStart == -1) nestedStart = i;
                } else if (s[i] == ']') {
                    n--;
                } else if (s[i] == ',' && n == 0) {
                    ni.add(helper(s, lastStart, i - 1));
                    lastStart = i + 1;
                }
                if (i == end) ni.add(helper(s, lastStart, end));
            }
        }
        return ni;
    }

public:
    NestedInteger deserialize(string s) {
        return helper(s, 0, s.size() - 1);
    }
};
