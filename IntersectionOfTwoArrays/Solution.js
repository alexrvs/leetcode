/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    var res = [];
    nums1.sort(function(a, b) { return a - b; });
    nums2.sort(function(a, b) { return a - b; });
    for (var i = 0, j = 0; i < nums1.length && j < nums2.length; ) {
        if (nums1[i] === nums2[j]) {
            res.push(nums1[i]);
            while ( ++i < nums1.length && nums1[i] === nums1[i - 1]);
            while ( ++j < nums2.length && nums2[j] === nums2[j - 1]);
        } else if (nums1[i] < nums2[j]) {
            while ( ++i < nums1.length && nums1[i] === nums1[i - 1]);
        } else {
            while ( ++j < nums2.length && nums2[j] === nums2[j - 1]);
        }
    }
    return res;
};
