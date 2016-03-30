class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char, int>> charStack;
        vector<bool> valid(s.size(), false);
        for (int i = 0; i < s.size(); i++) {
            if ( !charStack.empty() ) {
                char topChar = charStack.top().first;
                int topPos = charStack.top().second;
                if( topChar == '(' && s[i] == ')') {
                    charStack.pop();
                    for (int j = topPos; j <= i; ++j) {
                        valid[j] = true;
                    }
                } else {
                    charStack.push(make_pair(s[i], i));
                }
            } else {
                charStack.push(make_pair(s[i], i));
            }
        }

        int nowLen = 0;
        int maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            if(valid[i]) {
                nowLen++;
            } else {
                maxLen = max(maxLen, nowLen);
                nowLen = 0;
            }
        }
        maxLen = max(maxLen, nowLen);
        return maxLen;
    }
};
