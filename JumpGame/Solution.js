/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
    var size = nums.length;
    if (size === 0) return false;
    var reachable = nums[0];
    for (var i = 0; i < size && i <= reachable; i++) {
        if (i == size - 1) return true;
        canReach = i + nums[i];
        if (canReach > reachable) reachable = canReach;
    }
    return false;
};
