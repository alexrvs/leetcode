public class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int size = nums.length;
        for (int i = 0; i < size; i++) {
            while (nums[i] != i + 1) {
                int temp = nums[i];
                if (nums[temp - 1] == temp) break;
                nums[i] = nums[temp - 1];
                nums[temp - 1] = temp;
            }
        }
        List<Integer> res = new ArrayList<Integer>();
        for (int i = 0; i < size; i++) {
            if (nums[i] != i + 1) res.add(i + 1);
        }
        return res;
    }
}