public class Solution {
    public boolean isHappy(int n) {
        Set<Integer> used = new HashSet<Integer>();
        int sum = 0;
        int d = 0;
        while (n > 100 || !used.contains(n)) {
            if (n <= 100) used.add(n);
            sum = 0;
            while (n > 0) {
                d = n % 10;
                sum += d * d;
                n /= 10;
            }
            if (sum == 1) return true;
            n = sum;
        }
        return false;
    }
}
