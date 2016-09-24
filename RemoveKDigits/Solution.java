public class Solution {
    public String removeKdigits(String num, int k) {
        int size = num.length();
        String res = "";
        if (k >= size) {
            res = "0";
            return res;
        }
        List<Boolean> removed = new ArrayList<Boolean>();
        for (int i = 0; i < size; i++) {
            removed.add(false);
        }
        for (int i = 1; i < size && k > 0; i++) {
            for (int j = i - 1; j >= 0 && k > 0; j--) {
                if (num.charAt(j) <= num.charAt(i)) break;
                if (removed.get(j) == false) {
                    k--;
                    removed.set(j, true);
                }
            }
        }
        int last = size - 1;
        while (k > 0 && last >= 0) {
            if (removed.get(last) == false) {
                k--;
                removed.set(last, true);
            }
            last--;
        }
        for (int i = 0; i < size; i++) {
            if (removed.get(i) == false) {
                if (num.charAt(i) == '0' && res.length() == 0) continue;
                else res += num.charAt(i);
            }
        }
        if (res.length() == 0) {
            res = "0";
        }
        return res;
    }
}
