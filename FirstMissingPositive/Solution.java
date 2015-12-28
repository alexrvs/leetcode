public class Solution {
    public int firstMissingPositive(int[] nums) {
        int cur = 0;
        int tmp = 0;
        int l = nums.length;
        for (int i = 0; i < l; i++) {
            cur = nums[i];
            while (cur >= 1 && cur <= l && nums[cur - 1] != cur) {
                tmp = nums[cur - 1];
                nums[cur - 1] = cur;
                cur = tmp;
            }
        }
        for (int i = 0; i < l; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return l + 1;
    }
}
