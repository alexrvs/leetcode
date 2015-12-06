public class Solution {
    public String multiply(String num1, String num2) {
        String zero = "0";
        if (num1.equals(zero) || num2.equals(zero)) {
            return zero;
        }
        int l1 = num1.length();
        int l2 = num2.length();
        int[] n1 = new int[l1];
        int[] n2 = new int[l2];
        int[] num = new int[l1 + l2];
        for (int i = 0; i < l1; i++) {
            n1[i] = num1.charAt(i) - '0';
        }
        for (int i = 0; i < l2; i++) {
            n2[i] = num2.charAt(i) - '0';
        }
        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < l2; j++) {
                num[i + j + 1] += n1[i] * n2[j];
            }
        }
        for (int i = l1 + l2 - 1; i >= 0; i-- ) {
            if (i > 0) {
                num[i - 1] += num[i] / 10;
            }
            num[i] %= 10;
        }
        String res = "";
        if (num[0] != 0) {
            res += num[0];
        }
        for (int i = 1; i < l1 + l2; i++) {
            res += num[i];
        }
        return res;
    }
}
