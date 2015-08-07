import java.util.Map;
import java.util.HashMap;

public class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> numMap = new HashMap<Integer, Integer>();
        int[] res = new int[2];
        for (int i = 0; i < nums.length; i++) {
            int lookup = target - nums[i];
            if (numMap.get(lookup) != null) {
                res[0] = numMap.get(lookup) + 1;
                res[1] = i + 1;
                return res;
            }
            numMap.put(nums[i], i);
        }
        return res;
    }

}
