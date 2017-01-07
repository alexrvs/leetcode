public class Solution {
    public String shortestPalindrome(String s) {
        int size = s.length();
        if (size < 2) return s;
        String longStr = s + "#" + new StringBuilder(s).reverse();
        int len = 2 * size + 1;
        int[] table = new int[len];
        int idx = 0;
        for (int i = 1; i < len; i++) {
            if (longStr.charAt(i) == longStr.charAt(idx)) {
                table[i] = ++idx;
            }
            idx = table[i - 1];
            while (idx > 0 && longStr.charAt(i) != longStr.charAt(idx)) {
                idx = table[idx - 1];
            }
            if (longStr.charAt(i) == longStr.charAt(idx)) idx++;
            table[i] = idx;
        }
        return new StringBuilder(s.substring(table[len - 1])).reverse() + s;
    }
}