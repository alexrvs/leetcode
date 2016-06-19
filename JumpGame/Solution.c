bool canJump(int* nums, int numsSize) {
    if (numsSize == 1) return true;
    int reachable = nums[0];
    int from = 0;
    int nowReach = 0;
    while (from <= reachable) {
        nowReach = reachable;
        for (; from <= nowReach; from++) {
            int reach = from + nums[from];
            if (reach >= numsSize - 1) return true;
            if (reach >= reachable) reachable = reach;
        }
    }
    return false;
}
