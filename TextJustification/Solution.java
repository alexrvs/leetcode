public class Solution {
    private String addSpaces(String str, int i, int n, int len, boolean leftJust) {
        if (n < 1 || i > n - 1) return str;
        int spaces = leftJust ? 1 : (len/n + ((i < len%n) ? 1 : 0));
        while (spaces-- != 0) {
            str += " ";
        }
        return str;
    }

    private String connect(String[] words, int start, int end, int len, int maxWidth, boolean leftJust) {
        String s = "";
        for (int i = start; i <= end; i++) {
            s += addSpaces(words[i], i - start, end - start, maxWidth - len, leftJust);
        }
        while (s.length() < maxWidth) {
            s += " ";
        }
        return s;
    }

    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> res = new ArrayList<String>();
        int len = 0, begin = 0, i = 0;
        for (i = 0; i < words.length; i++) {
            if (len + words[i].length() + (i - begin) > maxWidth) {
                res.add(connect(words, begin, i - 1, len, maxWidth, false));
                begin = i;
                len = 0;
            }
            len += words[i].length();
        }
        res.add(connect(words, begin, i - 1, len, maxWidth, true));
        return res;
    }
}
