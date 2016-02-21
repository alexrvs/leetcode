public class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res = new int[2];
        int size = nums.length;
        int l = 0;
        int r = size;
        int m = 0;
        while (l < r) {
            m = l + (r - l) / 2;
            if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (l == size || nums[l] != target) {
            res[0] = -1;
            res[1] = -1;
            return res;
        }
        res[0] = l;
        l = 0;
        r = size;
        while (l < r) {
            m = l + (r - l) / 2;
            if (nums[m] <= target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        res[1] = l - 1;
        return res;
    }
}
