public class Solution {
    public int[] plusOne(int[] digits) {
        int size = digits.length;
        int c = 0;
        int d = 0;
        digits[size - 1] += 1;
        for (int i = size - 1; i >= 0; i--) {
            digits[i] += c;
            c = digits[i] / 10;
            digits[i] %= 10;
        }
        int[] res = null;
        int idx = 0;
        if (c == 1) {
            res = new int[size + 1];
            res[0] = 1;
            idx = 1;
        } else {
            res = new int[size];
        }
        for (int i = 0; i < size; i++) {
            res[idx] = digits[i];
            idx++;
        }
        return res;
    }
}
