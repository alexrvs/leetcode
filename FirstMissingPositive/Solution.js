/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
    var l = nums.length;
    var i = 0;
    for (i = 0; i < l; i++) {
        var cur = nums[i];
        while (cur >= 1 && cur <= l && nums[cur - 1] !== cur) {
            var tmp = nums[cur - 1];
            nums[cur - 1] = cur;
            cur = tmp;
        }
    }
    for (i = 0; i < l; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return l + 1;
};
