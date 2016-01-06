public class Solution {
    private void helper(int[] nums, int target, int f, int s, List<List<Integer> > res) {
        int l = s + 1;
        int r = nums.length - 1;
        while (l < r) {
            int sum = nums[f] + nums[s] + nums[l] + nums[r];
            if (sum < target) {
                l++;
            } else if (sum > target) {
                r--;
            } else {
                List<Integer> path = new ArrayList<Integer>();
                path.add(nums[f]);
                path.add(nums[s]);
                path.add(nums[l]);
                path.add(nums[r]);
                res.add(path);
                while ( ++l < r && nums[l - 1] == nums[l]);
            }
        }
    }

    public List<List<Integer>> fourSum(int[] nums, int target) {
        int size = nums.length;
        List<List<Integer> > res = new ArrayList<List<Integer> >();
        Arrays.sort(nums);
        for (int i = 0; i < size - 3;) {
            if (i + 4 < size && nums[i + 4] == nums[i + 3] &&
                    nums[i + 3] == nums[i + 2] && nums[i + 2] == nums[i + 1] &&
                    nums[i + 1] == nums[i]) {
                i++;
                continue;
            } else {
                for (int j = i + 1; j < size - 2;) {
                    helper(nums, target, i, j, res);
                    while (++j < size && nums[j - 1] == nums[j]);
                }
            }
            while (++i < size && nums[i - 1] == nums[i]);
        }
        return res;
    }
}
