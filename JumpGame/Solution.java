public class Solution {
    public boolean canJump(int[] nums) {
        int size = nums.length;
        if (size == 0) return false;
        int reachable = nums[0];
        int can_reach = 0;
        for (int i = 0; i < size && i <= reachable; i++) {
            if (i == size - 1) return true;
            can_reach = i + nums[i];
            if (can_reach > reachable) reachable = can_reach;
        }
        return false;
    }
}
