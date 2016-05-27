public class Solution {
    public int majorityElement(int[] nums) {
        int major = nums[0];
        int c = 1;
        for (int i = 1; i < nums.length; i++) {
            if (c != 0) {
                if (major != nums[i]) c--;
                else c++;
            } else {
                major = nums[i];
                c = 1;
            }
        }
        return major;
    }
}
