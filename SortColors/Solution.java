public class Solution {
    public void sortColors(int[] nums) {
        int[] cnts = new int[3];
        int size = nums.length;
        for (int i = 0; i < size; i++) {
            cnts[nums[i]]++;
        }
        int idx = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < cnts[i]; j++) {
                nums[idx++] = i;
            }
        }
        return;
    }
}
