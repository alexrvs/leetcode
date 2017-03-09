public class Solution {
    public int findMaxLength(int[] nums) {
        int size = nums.length;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        map.put(0, 0);
        int[] diff = new int[size + 1];
        int max = 0;
        for (int i = 1; i <= size; i++) {
            diff[i] = diff[i - 1] + (nums[i - 1] == 1 ? 1 : -1);
            if (map.containsKey(diff[i])) {
                int l = i - map.get(diff[i]);
                if (max < l) {
                    max = l;
                }
            } else {
                map.put(diff[i], i);
            }
        }
        return max;
    }
}