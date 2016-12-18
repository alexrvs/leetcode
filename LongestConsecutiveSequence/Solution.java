public class Solution {
    public int longestConsecutive(int[] nums) {
        int res = 0;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            int n = nums[i];
            if (!map.containsKey(n)) {
                int left = 0;
                int right = 0;
                if (map.containsKey(n - 1)) left = map.get(n - 1);
                if (map.containsKey(n + 1)) right = map.get(n + 1);
                int sum = left + right + 1;
                map.put(n, sum);
                map.put(n - left, sum);
                map.put(n + right, sum);
                if (res < sum) res = sum;
            }
        }
        return res;
    }
}