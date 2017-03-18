/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNonDuplicate = function(nums) {
    let l = 0;
    let r = nums.length;
    while (l < r) {
        let m = l + ((r - l) >> 2);
        if (m - 1 >= 0 && nums[m - 1] == nums[m]) {
            if ((r - m) % 2 === 0) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        } else if (m + 1 < nums.length && nums[m + 1] == nums[m]) {
            if ((m - l) % 2 == 1) {
                r = m;
            } else {
                l = m + 2;
            }
        } else {
            return nums[m];
        }
    }
    return nums[l];
};