public class Solution {
    public void reverse(int[] nums, int i, int j) {
        int tmp = 0;
        while (i < j) {
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i++;
            j--;
        }
        return;
    }

    public void rotate(int[] nums, int k) {
        int size = nums.length;
        k = k%size;
        if (k > 0) {
            reverse(nums, 0, size - 1);
            reverse(nums, 0, k - 1);
            reverse(nums, k, size - 1);
        }
        return;
    }
}
