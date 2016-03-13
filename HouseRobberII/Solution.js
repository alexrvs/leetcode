var helper = function(nums, start, end) {
    var l = nums.length;
    var sums = new Array(l);
    var max = 0;
    for (var i = start; i <= end; i++) {
        sums[i] = 0;
        if (i - 3 >= start && max < nums[i] + sums[i - 3]) {
            max = nums[i] + sums[i - 3];
        }
        if (i - 2 >= start && max < nums[i] + sums[i - 2]) {
            max = nums[i] + sums[i - 2];
        }
        if (max < nums[i]) max = nums[i];
        sums[i] = max;
    }
    return max;
};

/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    var l = nums.length;
    if (l == 1) return nums[0];
    var m1 = helper(nums, 0, l - 2);
    var m2 = helper(nums, 1, l - 1);
    return (m1 > m2 ? m1 : m2);
};
