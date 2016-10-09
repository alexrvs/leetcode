public class Solution {
    public String addStrings(String num1, String num2) {
        int size1 = num1.length();
        int size2 = num2.length();
        if (size1 < size2) return addStrings(num2, num1);
        int[] digits = new int[size1];
        int s = 0;
        int c = 0;
        for (int i = 0; i < size1; i++) {
            int d1 = num1.charAt(size1 - 1 - i) - '0';
            int d2 = 0;
            if (size2 - 1 - i >= 0) d2 = num2.charAt(size2 - 1 - i) - '0';
            s = d1 + d2 + c;
            c = s / 10;
            digits[size1 - 1 - i] = s % 10;
        }
        String res = "";
        if (c == 1) res += "1";
        for (int i = 0; i < size1; i++) {
            res += digits[i];
        }
        return res;
    }
}