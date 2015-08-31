public class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int size = gas.length;
        int start = -1;
        int tank = 0;
        int cur = 0;
        for (int i = 0; i < 2*size; i++) {
            cur = i%size;
            if (cur == start) return start;
            tank += gas[cur] - cost[cur];
            if (tank >= 0) {
                if (start == -1) {
                    start = cur;
                }
            } else {
                start = -1;
                tank = 0;
            }
        }
        return -1;
    }
}
