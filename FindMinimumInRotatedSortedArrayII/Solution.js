/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    let size = nums.length;
    if (size === 0) return 0;
    let l = 0;
    let r = size - 1;
    let m = 0;
    while (l < r) {
        m = l + ((r - l) >> 1);
        if (nums[r] < nums[m]) {
            l = m + 1;
        } else if (nums[m] < nums[r]) {
            r = m;
        } else {
            if (nums[l] == nums[m]) {
                l++;
                r--;
            } else {
                r = m;
            }
        }
    }
    return nums[r];
};