public class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int cnt = 0;
        int size = A.length;
        if (A == null || size < 3) return cnt;
        List<Map<Integer,Integer>> dp = new ArrayList<Map<Integer,Integer>>();
        for (int i = 0; i < size; i++) {
            dp.add(new HashMap<Integer,Integer>());
            Map<Integer, Integer> dp_i = dp.get(i);
            for (int j = 0; j < i; j++) {
                if ((long) A[i] - (long) A[j] > Integer.MAX_VALUE || 
                    (long) A[i] - (long) A[j] < Integer.MIN_VALUE) {
                        continue;
                }
                int diff = A[i] - A[j];
                if (j == 0) {
                    dp_i.put(diff, 1);
                    continue;
                }
                Map<Integer,Integer> dp_j = dp.get(j);
                int sum = 0;
                if (dp_j.containsKey(diff)) {
                    sum = dp_j.get(diff);
                }
                if (dp_i.containsKey(diff)) {
                    dp_i.put(diff, dp_i.get(diff) + sum + 1);
                } else {
                    dp_i.put(diff, sum + 1);
                }
                cnt += sum;
            }
        }
        return cnt;
    }
}