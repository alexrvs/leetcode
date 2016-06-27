/**
 * @param {number[]} nums
 * @return {number[]}
 */
var largestDivisibleSubset = function(nums) {
    var size = nums.length;
    nums.sort(function(a, b) {return a - b;});
    var steps = [];
    var idx = [];
    var maxSteps = 0;
    var maxIdx = 0;
    for (var i = 0; i < size; i++) {
        steps.push(1);
        idx.push(i);
        if (maxSteps < steps[i]) {
            maxSteps = steps[i];
            maxIdx = i;
        }
        for (var j = i - 1; j >= 0; j--) {
            if (nums[i] % nums[j] === 0) {
                steps[i] = steps[j] + 1;
                idx[i] = j;
                if (maxSteps < steps[i]) {
                    maxSteps = steps[i];
                    maxIdx = i;
                }
                break;
            }
        }
    }
    var res = [];
    while (maxSteps-- !== 0) {
        res.push(nums[maxIdx]);
        maxIdx = idx[maxIdx];
    }
    return res.reverse();
};
