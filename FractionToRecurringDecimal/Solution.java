public class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        Map<Long, Integer> remainIdx = new HashMap<Long, Integer>();
        boolean neg = false;
        long num = (long) numerator;
        long den = (long) denominator;
        if (num * den < 0) neg = true;
        num = num < 0 ? -num : num;
        den = den < 0 ? -den : den;
        long remain = num % den;
        List<Long> factors = new ArrayList<Long>();
        int repeatStart = -1;
        String res = "";
        res += num / den;
        if (remain == 0) return neg == true ? "-" + res : res;
        res += ".";
        while (remain != 0) {
            if (remainIdx.containsKey(remain)) {
                repeatStart = remainIdx.get(remain);
                break;
            } else {
                remainIdx.put(remain, factors.size());
                remain *= 10;
                factors.add(remain / den);
                remain = remain % den;
                System.out.println(remain + " : " + factors.get(factors.size() - 1) );
            }
        }
        if (repeatStart != -1) {
            for (int i = 0; i < repeatStart; i++) {
                res += factors.get(i);
            }
            res += "(";
            for (int i = repeatStart; i < factors.size(); i++) {
                res += factors.get(i);
            }
            res += ")";
        } else {
            for (int i = 0; i < factors.size(); i++) {
                res += factors.get(i);
            }
        }
        if (neg == true) {
            res = "-" + res;
        }
        return res;
    }
}
