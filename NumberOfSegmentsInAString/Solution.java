public class Solution {
    public int countSegments(String s) {
        int size = s.length();
        boolean hasChar = false;
        int cnt = 0;
        for (int i = 0; i < size; i++) {
            if (s.charAt(i) != ' ' && s.charAt(i) != '\n') {
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
}