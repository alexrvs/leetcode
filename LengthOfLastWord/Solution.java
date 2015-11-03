public class Solution {
    public int lengthOfLastWord(String s) {
        int size = s.length();
        int len = 0;
        for (int i = size - 1; i >= 0; i--) {
            char c = s.charAt(i);
            if (c == ' ') {
                if (len == 0) continue;
                return len;
            }
            len++;
        }
        return len;
    }
}
