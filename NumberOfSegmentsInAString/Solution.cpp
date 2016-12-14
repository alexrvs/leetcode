class Solution {
public:
    int countSegments(string s) {
        int size = s.size();
        bool hasChar = false;
        int cnt = 0;
        for (int i = 0; i < size; i++) {
            if (s[i] != ' ' && s[i] != '\n') {
                hasChar = true;
            } else {
                if (true == hasChar) {
                    hasChar = false;
                    cnt++;
                }
            }
        }
        if (true == hasChar) {
            cnt++;
        }
        return cnt;
    }
};