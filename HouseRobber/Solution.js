/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    var size = nums.length;
    if (size === 0) return 0;
    if (size == 1) return nums[0];
    for (var i = 1; i < size; i++) {
        var pred = i > 4 ? i - 4 : 0;
        var max = nums[i];
        for (var j = pred; j < i - 1; j++) {
            var sum = nums[i] + nums[j];
            if (max < sum) max = sum;
        }
        nums[i] = max;
    }
    return nums[size - 1] > nums[size - 2] ? nums[size - 1] : nums[size - 2];
};
