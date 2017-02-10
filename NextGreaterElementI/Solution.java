public class Solution {
    public int[] nextGreaterElement(int[] findNums, int[] nums) {
        int l1 = findNums.length;
        int[] res = new int[l1];
        for (int i = 0; i < findNums.length; i++) {
            boolean find = false;
            boolean findGreater = false;
            for (int j = 0; j < nums.length; j++) {
                if (findNums[i] == nums[j]) find = true;
                if (find == true && findNums[i] < nums[j]) {
                    findGreater = true;
                    res[i] = nums[j];
                    break;
                }
            }
            if (findGreater == false) {
                res[i] = -1;
            }
        }
        return res;
    }
}