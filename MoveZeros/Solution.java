public class Solution {
    public void moveZeroes(int[] nums) {
        int size = nums.length;
        int cur = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] != 0) {
                nums[cur++] = nums[i];
            }
        }
        for (; cur < size; cur++) {
            nums[cur] = 0;
        }
        return;
    }
}
