/**
 * @param {number[]} nums
 * @return {number[]}
 */
var nextGreaterElements = function(nums) {
    let size = nums.length;
    let res = [];
    if (size === 0) return res;
    for (let i = 0; i < size; i++) {
        res.push(-1);
        for (let j = 1; j < size; j++) {
            let idx = (i + j) % size;
            if (nums[i] < nums[idx]) {
                res[i] = nums[idx];
                break;
            }
        }
    }
    return res;
};