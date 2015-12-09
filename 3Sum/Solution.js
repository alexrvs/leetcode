/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    　var res = [];
    　var l = nums.length;
    　nums.sort(function(a,b){ return a - b; });
    　var prev = 0;
    　for (var i = 0; i < l - 2; ) {
    　    for (var j = i + 1, k = l - 1; j < k;) {
    　        var sum = nums[i] + nums[j] + nums[k];
    　        if (sum === 0) {
    　            var r = [];
    　            r.push(nums[i]);
    　            r.push(nums[j]);
    　            r.push(nums[k]);
    　            res.push(r);
    　            prev = nums[j];
    　            while (j < k && nums[j] == prev) j++;
    　        } else if (sum < 0) {
    　            prev = nums[j];
    　            while (j < k && nums[j] == prev) j++;
    　        } else {
    　            prev = nums[k];
    　            while (j < k && nums[k] == prev) k--;
    　        }
    　    }
    　    prev = nums[i];
    　    while (i < l && nums[i] == prev) i++;
    　}
    　return res;
};
