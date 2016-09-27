public class Solution {
    public String decodeString(String s) {
        int size = s.length();
        int prev = -1;
        String res = "";
        int num = 0;
        int n = 0;
        for (int i = 0; i < size; i++) {
            if (s.charAt(i) == '[') {
                n++;
                if (prev == -1) prev = i + 1;
            } else if (s.charAt(i) == ']') {
                n--;
                if (n == 0) {
                    String sub = decodeString(s.substring(prev, i));
                    while (num > 0) {
                        res += sub;
                        num--;
                    }
                    prev = -1;
                }
            } else if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                if (n == 0) num = 10 * num + s.charAt(i) - '0';
            } else {
                if (n == 0) res += s.charAt(i);
            }
        }
        return res;
    }
}
