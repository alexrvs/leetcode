/**
 * @param {number[]} nums
 * @return {number}
 */
var jump = function(nums) {
    var size = nums.length;
    if (size == 1) return 0;
    var jumps = 0;
    var from = 0;
    var reachable = 0;
    while (from <= reachable) {
        jumps++;
        var nowReach = reachable;
        for (; from <= nowReach; from++) {
            var canReach = from + nums[from];
            if (canReach >= size - 1) return jumps;
            if (canReach > reachable) reachable = canReach;
        }
    }
    return 0;
};
