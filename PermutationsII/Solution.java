public class Solution {
    private void dfs(int[] nums, int idx, int[] used, int[] order, List<List<Integer>> res) {
        int size = nums.length;
        if (idx == size) {
            List<Integer> r = new ArrayList<Integer>();
            for (int i = 0; i < size; i++) {
                r.add(nums[order[i]]);
            }
            res.add(r);
            return;
        }
        for (int i = 0; i < size; i++) {
            if (used[i] == 0) {
                used[i] = 1;
                order[idx] = i;
                dfs(nums, idx + 1, used, order, res);
                used[i] = 0;
                while (i + 1 < size && nums[i] == nums[i + 1]) i++;
            }
        }
    }

    public List<List<Integer>> permuteUnique(int[] nums) {
        int size = nums.length;
        int[] used = new int[size];
        int[] order = new int[size];
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        dfs(nums, 0, used, order, res);
        return res;
    }
}
