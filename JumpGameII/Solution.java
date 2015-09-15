public class Solution {
    public int jump(int[] nums) {
        int size = nums.length;
        if (size == 1) return 0;
        int reachable = 0;
        int from = 0;
        int jumps = 0;
        int nowReach, canReach;
        while (from <= reachable) {
            jumps++;
            nowReach = reachable;
            for (; from <= nowReach; from++) {
                canReach = from + nums[from];
                if (canReach >= size - 1) return jumps;
                if (canReach > reachable) reachable = canReach;
            }
        }
        return 0;
    }
}
