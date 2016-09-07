class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sLen = s.size();
        int tLen = t.size();
        if (sLen == 0) return true;
        int idx = 0;
        for (int i = 0; i < tLen; i++) {
            if (idx < sLen && t[i] == s[idx]) {
                idx++;
                if (idx == sLen) return true;
            }
        }
        return false;
    }
};
