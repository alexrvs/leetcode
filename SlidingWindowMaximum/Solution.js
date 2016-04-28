/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSlidingWindow = function(nums, k) {
    var l = nums.length;
    var can = [];
    var first = 0;
    var last = -1;
    var size = 0;
    var res = [];
    for (var i = 0; i < l; i++) {
        if (size !== 0 && can[first] < i - k + 1) {
            first = (first + 1) % k;
            size--;
        }
        while (size !== 0 && nums[can[last]] < nums[i]) {
            last = (last + k - 1) % k;
            size--;
        }
        last = (last + 1) % k;
        can[last] = i;
        size++;
        if (i >= k - 1) {
            res.push(nums[can[first]]);
        }
    }
    return res;
};
