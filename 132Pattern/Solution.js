/**
 * @param {number[]} nums
 * @return {boolean}
 */
var find132pattern = function(nums) {
    let size = nums.length;
    let largers = [];
    let s3 = nums[0];
    for (let i = 0; i < size; i++) {
        if (s3 > nums[i]) {
            s3 = nums[i];
        }
    }
    for (let i = size - 1; i >= 0; i--) {
        if (nums[i] < s3) {
            return true;
        } else {
            while (0 !== largers.length && largers[largers.length - 1] < nums[i]) {
                s3 = largers[largers.length - 1];
                largers.pop();
            }
        }
        largers.push(nums[i]);
    }
    return false;
};