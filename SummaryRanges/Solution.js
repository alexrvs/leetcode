/**
 * @param {number[]} nums
 * @return {string[]}
 */
var summaryRanges = function(nums) {
    var ranges = [];
    var size = nums.length;
    if (size === 0) return ranges;
    var start = nums[0];
    for (var i = 1; i < size; i++) {
        if (nums[i] != nums[i-1] + 1) {
            if (nums[i-1] == start) {
                range = String(start);
            } else {
                range = String(start) + "->" + String(nums[i-1]);
            }
            ranges.push(range);
            start = nums[i];
        }
    }
    if (nums[size-1] == start) {
        range = String(start);
    } else {
        range = String(start) + "->" + String(nums[size-1]);
    }
    ranges.push(range);
    return ranges;
};
