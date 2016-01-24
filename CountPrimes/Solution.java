public class Solution {
    public int countPrimes(int n) {
        if (n < 3) return 0;
        if (n < 5) return n - 2;
        int l = 0;
        while (l * l < n) {
            l++;
        }
        int[] nums = new int[n];
        for (int i = 2; i <= l; i++) {
            if (nums[i] != 1) {
                for (int j = 2 * i; j < n; j += i) {
                    nums[j] = 1;
                }
            }
        }
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (nums[i] != 1) cnt++;
        }
        return cnt;
    }
}
