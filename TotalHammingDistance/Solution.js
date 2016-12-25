/**
 * @param {number[]} nums
 * @return {number}
 */
var totalHammingDistance = function(nums) {
    let zeros = new Array(32);
    let ones = new Array(32);
    for (let i = 0; i < 32; i++) {
        zeros[i] = 0;
        ones[i] = 0;
    }
    let size = nums.length;
    let mask = 0x1;
    for (let i = 0; i < size; i++) {
        let tmp = nums[i];
        for (let j = 0; j < 32; j++) {
            if ((tmp & mask) === 0) {
                zeros[j]++;
            } else {
                ones[j]++;
            }
            tmp >>= 1;
        }
    }
    let res = 0;
    for (let i = 0; i < 32; i++) {
        res += zeros[i] * ones[i];
    }
    return res;
};