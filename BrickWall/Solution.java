public class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        int r = wall.size();
        if (r == 0) return 0;
        int c = wall.get(0).size();
        if (c == 0) return 0;
        Map<Integer, Integer> sumCnt = new HashMap<Integer, Integer>();
        int max = 0;
        for (int i = 0; i < r; i++) {
            int sum = 0;
            for (int j = 0; j < wall.get(i).size() - 1; j++) {
                sum += wall.get(i).get(j);
                if (!sumCnt.containsKey(sum)) {
                    sumCnt.put(sum, 1);
                } else {
                    int cnt =  sumCnt.get(sum) + 1;
                    sumCnt.put(sum, cnt);
                }
                if (max < sumCnt.get(sum)) {
                    max = sumCnt.get(sum);
                }
            }
        }
        return r - max;
    }
}