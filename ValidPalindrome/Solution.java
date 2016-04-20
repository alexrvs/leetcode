public class Solution {
    private char toOrd(char c) {
        int ord = c - '0';
        if (0 <= ord && ord <= 9) return c;
        ord = c - 'a';
        if (0 <= ord && ord <= 26) return c;
        ord = c - 'A';
        if (0 <= ord && ord <= 26) {
            char[] chars = Character.toChars('a' + ord);
            return chars[0];
        };
        return 0;
    }

    public boolean isPalindrome(String s) {
        int size = s.length();
        int l = 0;
        int r = size - 1;
        while (l < r) {
            char lo = toOrd(s.charAt(l));
            if (lo == 0) {
                l++;
                continue;
            }
            char ro = toOrd(s.charAt(r));
            if (ro == 0) {
                r--;
                continue;
            }
            if (lo != ro) return false;
            l++;
            r--;
        }
        return true;
    }
}
