public class Solution {
    public boolean checkRecord(String s) {
        int aCnt = 0;
        int lCnt = 0;
        int size = s.length();
        for (int i = 0; i < size; i++) {
            if ('A' == s.charAt(i)) {
                lCnt = 0;
                if (++aCnt > 1) {
                    return false;
                }
            } else if ('L' == s.charAt(i)) {
                if (++lCnt > 2) {
                    return false;
                }
            } else {
                lCnt = 0;
            }
        }
        return true;
    }
}