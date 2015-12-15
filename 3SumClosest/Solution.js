/**
 *  * @param {number[]} nums
 *   * @param {number} target
 *    * @return {number}
 *     */
var threeSumClosest = function(nums, target) {
    var closest = 0;
    var l = nums.length;
    if (l < 3) return closest;
    nums.sort(function(a, b) { return a - b; });
    closest = nums[0] + nums[1] + nums[2];
    var minDist = 0;
    if (closest < target) {
        minDist = target - closest;
    } else {
        minDist = closest - target;
    }
    var i, j, k;
    for (i = 0; i < l - 2; i++) {
        for (j = i + 1, k = l - 1; j < k; ) {
            var sum = nums[i] + nums[j] + nums[k];
            if (sum == target) {
                return sum;
            } else if (sum < target) {
                if (target - sum < minDist) {
                    minDist = target - sum;
                    closest = sum;
                }
                j++;
            } else {
                if (sum - target < minDist) {
                    minDist = sum - target;
                    closest = sum;
                }
                k--;
            }
        }
    }
    return closest;
};
