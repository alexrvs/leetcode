public class Solution {
    private int getMax(int a, int b) {
        return (a > b ? a : b);
    }

    private int getMin(int a, int b) {
        return (a < b ? a : b);
    }

    public int maxProduct(int[] nums) {
        int res = nums[0];
        int tmax = nums[0];
        int tmin = nums[0];
        for (int i = 1; i < nums.length; i++) {
            int prod1 = tmax * nums[i];
            int prod2 = tmin * nums[i];
            tmax = getMax(getMax(prod1, prod2), nums[i]);
            tmin = getMin(getMin(prod1, prod2), nums[i]);
            res = getMax(tmax, res);
        }
        return res;
    }
}
