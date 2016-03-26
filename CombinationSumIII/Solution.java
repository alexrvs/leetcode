public class Solution {
    private void helper(int k, List<Integer> path, int idx, int sum, List<List<Integer>> res) {
        if (k < 0 || sum < 0) return;
        if (k == 0 && sum == 0) {
            res.add(new ArrayList<Integer>(path));
            return;
        }
        for (int i = idx; i <= 9; i++) {
            path.add(i);
            helper(k - 1, path, i + 1, sum - i, res);
            path.remove(path.size() - 1);
        }
    }

    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> path = new ArrayList<Integer>();
        helper(k, path, 1, n, res);
        return res;
    }
}
