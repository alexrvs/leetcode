public class Solution {
    private void helper(int[] candidates, List<Integer> path, int index, int sum, int target, List<List<Integer>> res) {
        if (sum > target) return;
        if (sum == target) {
            res.add(new ArrayList<Integer>(path));
            return;
        }
        for (int i = index; i < candidates.length; i++) {
            path.add(candidates[i]);
            helper(candidates, path, i, sum + candidates[i], target, res);
            path.remove(path.size() - 1);
        }
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> path = new ArrayList<Integer>();
        helper(candidates, path, 0, 0, target, res);
        return res;
    }
}
