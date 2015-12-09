public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer> > res = new ArrayList<List<Integer> >();
        int size = nums.length;
        if (size < 3) return res;
        Arrays.sort(nums);
        int prev = 0;
        int sum = 0;
        for (int i = 0; i < size - 2;) {
            for (int j = i + 1, k = size - 1; j < k; ) {
                sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    List<Integer> r = new ArrayList<Integer>();
                    r.add(nums[i]);
                    r.add(nums[j]);
                    r.add(nums[k]);
                    res.add(r);
                    prev = nums[j];
                    while (j < k && nums[j] == prev) j++;
                } else if (sum < 0) {
                    prev = nums[j];
                    while (j < k && nums[j] == prev) j++;
                } else {
                    prev = nums[k];
                    while (j < k && nums[k] == prev) k--;
                }
            }
            prev = nums[i];
            while (i < size && nums[i] == prev) i++;
        }
        return res;
    }
}
