public class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1)
            return s;
        String res = "";
        int step = 2 * (numRows - 1);
        int length = s.length();
        int index = 0;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; ; j++) {
                if (i == 0 || i == numRows - 1) {
                    index = step*j + i;
                    if (index < length) {
                        res += s.charAt(index);
                    }
                    else
                        break;
                } else {
                    index = step*j - i;
                    if (index > 0 && index < length) {
                        res += s.charAt(index);
                    }
                    index = step*j + i;
                    if (index < length) {
                        res += s.charAt(index);
                    }
                    else
                        break;
                }
            }
        }
        return res;
    }
}
