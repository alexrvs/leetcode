/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    var l = nums.length;
    if (l === 0) return 0;
    var noDupIdx = 0;
    var dup = false;
    for (var i = 1; i < l; i++) {
        if (nums[i] != nums[noDupIdx]) {
            dup = false;
            nums[++noDupIdx] = nums[i];
        } else if (dup === false) {
            dup = true;
            nums[++noDupIdx] = nums[i];
        }
    }
    return noDupIdx + 1;
};
