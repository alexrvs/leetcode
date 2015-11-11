public class Solution {
    public String addBinary(String a, String b) {
        int aSize = a.length();
        int bSize = b.length();
        int size = aSize > bSize ? aSize : bSize;
        int c = 0;
        int[] d = new int[size];
        for (int i = 0; i < size; i++) {
            int ad = 0;
            int bd = 0;
            if (aSize - 1 - i >= 0) ad = a.charAt(aSize - 1 - i) - '0';
            if (bSize - 1 - i >= 0) bd = b.charAt(bSize - 1 - i) - '0';
            d[i] = ad + bd + c;
            c = d[i] / 2;
            d[i] %= 2;
        }
        String res = "";
        if (c == 1) res += "1";
        for (int i = size - 1; i >= 0; i--) {
            res += d[i];
        }
        return res;
    }
}
