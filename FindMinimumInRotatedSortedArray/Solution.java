public class Solution {
    public int findMin(int[] nums) {
        int l = 0;
        int r = nums.length;
        int m = 0;
        while (l < r) {
            m = l + (r - l) / 2;
            if (nums[m] >= nums[0]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (l >= nums.length) return nums[0];
        return nums[l];
    }
}
