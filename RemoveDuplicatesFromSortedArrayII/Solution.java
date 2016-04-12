public class Solution {
    public int removeDuplicates(int[] nums) {
        int size = nums.length;
        if (size == 0) return 0;
        int noDupIdx = 0;
        boolean dup = false;
        for (int i = 1; i < size; i++) {
            if (nums[i] != nums[noDupIdx]) {
                noDupIdx++;
                nums[noDupIdx] = nums[i];
                dup = false;
            } else if (dup == false) {
                dup = true;
                noDupIdx++;
                nums[noDupIdx] = nums[i];
            }
        }
        return noDupIdx + 1;
    }
}
