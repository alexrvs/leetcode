/**
 * @param {number[]} nums
 * @return {number[]}
 */
var majorityElement = function(nums) {
    var num1 = null;
    var num2 = null;
    var cnt1, cnt2;
    cnt1 = 0;
    cnt2 = 0;
    for (var i = 0; i < nums.length; i++) {
        if (cnt1 > 0 && nums[i] == num1) { cnt1++; continue; }
        if (cnt2 > 0 && nums[i] == num2) { cnt2++; continue; }
        if (cnt1 === 0) { num1 = nums[i]; cnt1++; continue; }
        if (cnt2 === 0) { num2 = nums[i]; cnt2++; continue; }
        cnt1--; cnt2--;
    }
    if (cnt1 === 0) num1 = null;
    if (cnt2 === 0) num2 = null;
    cnt1 = 0;
    cnt2 = 0;
    for (i = 0; i < nums.length; i++) {
        if (nums[i] === num1) cnt1++;
        if (nums[i] === num2) cnt2++;
    }
    var res = [];
    if (cnt1 > nums.length / 3) res.push(num1);
    if (cnt2 > nums.length / 3) res.push(num2);
    return res;
};
