public class Solution {
    private void helper(int[] candidates, List<Integer> path, int index, int sum, List<List<Integer>> res) {
        if (sum < 0) return;
        if (sum == 0) {
            res.add(new ArrayList<Integer>(path));
            return;
        }
        int prev = 0;
        for (int i = index; i < candidates.length; i++) {
            if (i > 0 && candidates[i] == prev) continue;
            path.add(candidates[i]);
            helper(candidates, path, i + 1, sum - candidates[i], res);
            path.remove(path.size() - 1);
            prev = candidates[i];
        }
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> path = new ArrayList<Integer>();
        helper(candidates, path, 0, target, res);
        return res;
    }
}
