public class Solution {
    private char getCharAt(String str, int i) {
        if (i < str.length()) return str.charAt(i);
        return '\0';
    }
    public boolean isMatch(String s, String p) {
        int len1 = s.length();
        int len2 = p.length();
        int i = 0;
        int j = 0;
        int starIdx = 0;
        int saveIdx = 0;
        boolean star = false;
        while (i < len1) {
            if (getCharAt(p, j) == '?') {
                i++;
                j++;
            } else if (getCharAt(p, j) == '*') {
                do {
                    j++;
                } while (getCharAt(p, j) == '*');
                saveIdx = i;
                starIdx = j;
                star = true;
            } else {
                if (getCharAt(s, i) == getCharAt(p, j)) {
                    i++;
                    j++;
                } else {
                    if (star == true) {
                        i = ++saveIdx;
                        j = starIdx;
                    } else {
                        return false;
                    }
                }
            }
        }
        while (getCharAt(p, j) == '*') {
            j++;
        }
        return (i == len1 && j == len2);
    }
}
