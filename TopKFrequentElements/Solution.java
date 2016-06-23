public class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        int size = nums.length;
        Map<Integer, Integer> counts = new HashMap<Integer, Integer>();
        for (int n : nums) {
            if (counts.containsKey(n)) counts.put(n, counts.get(n) + 1);
            else counts.put(n, 1);
        }
        List<Integer>[] buckets = new ArrayList[size + 1];
        for (int n : counts.keySet()) {
            int cnt = counts.get(n);
            if (buckets[cnt] == null) {
                buckets[cnt] = new ArrayList<Integer>();
            }
            buckets[cnt].add(n);
        }
        List<Integer> res = new ArrayList<Integer>();
        for (int i = size; i >= 0 && res.size() < k; i--) {
            if (buckets[i] != null) {
                res.addAll(buckets[i]);
            }
        }
        return res;
    }
}
