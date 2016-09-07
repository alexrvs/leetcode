public class Solution {
    public boolean isSubsequence(String s, String t) {
        int sLen = s.length();
        int tLen = t.length();
        if (sLen == 0) return true;
        int idx = 0;
        for (int i = 0; i < tLen; i++) {
            if (t.charAt(i) == s.charAt(idx)) {
                idx++;
                if (idx == sLen) return true;
            }
        }
        return false;
    }
}
