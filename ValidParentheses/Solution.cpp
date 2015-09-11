class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        stack<char> left;
        for (int i = 0; i < size; i++) {
            switch(s[i]) {
                case '(':
                case '[':
                case '{':
                    left.push(s[i]);
                    break;
                case ')':
                    if (left.size() > 0 && '(' ==left.top()) {
                        left.pop();
                    } else return false;
                    break;
                case '}':
                    if (left.size() > 0 && '{' ==left.top()) {
                        left.pop();
                    } else return false;
                    break;
                case ']':
                    if (left.size() > 0 && '[' ==left.top()) {
                        left.pop();
                    } else return false;
                    break;
            }
        }
        if (left.size() > 0) return false;
        return true;
    }
};
