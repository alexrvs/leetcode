class Solution {
public:
    bool checkRecord(string s) {
        int aCnt = 0;
        int lCnt = 0;
        int size = s.size();
        for (int i = 0; i < size; i++) {
            if ('A' == s[i]) {
                lCnt = 0;
                if (++aCnt > 1) {
                    return false;
                }
            } else if ('L' == s[i]) {
                if (++lCnt > 2) {
                    return false;
                }
            } else {
                lCnt = 0;
            }
        }
        return true;
    }
};