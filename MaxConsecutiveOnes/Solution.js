/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    let cnt = 0;
    let size = nums.length;
    let max = 0;
    for (let i = 0; i < size; i++) {
        if (nums[i] === 0) cnt = 0;
        else {
            cnt++;
            if (max < cnt) max = cnt;
        }
    }
    return max;
};