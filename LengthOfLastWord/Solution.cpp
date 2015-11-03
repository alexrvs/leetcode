class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.size();
        int len = 0;
        for (int i = size - 1; i >= 0; i--) {
            char c = s[i];
            if (c == ' ') {
                if (len == 0) continue;
                else return len;
            } else {
                len++;
            }
        }
        return len;
    }
};
