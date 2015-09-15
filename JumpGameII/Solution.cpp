class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return 0;
        int jumps = 0;
        int from = 0;
        int reachable = 0;
        int nowReach = 0;
        while (from <= reachable) {
            jumps++;
            nowReach = reachable;
            for (int i = from; i <= nowReach; i++) {
                int canReach = i + nums[i];
                if (canReach >= size-1)
                    return jumps;
                if (canReach > reachable) {
                    reachable = canReach;
                }
            }
            from = nowReach + 1;
        }
        return 0;
    }
};
