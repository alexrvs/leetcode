/**
 * @constructor
 * @param {number[]} nums
 */
var NumArray = function(nums) {
    this.sums = [];
    this.nums = nums;
    var size = nums.length;
    this.sums.push(0);
    for (var i = 1; i < size; i++) {
        this.sums.push(this.sums[i - 1] + this.nums[i - 1]);
    }
};

/**
 * @param {number} i
 * @param {number} j
 * @return {number}
 */
NumArray.prototype.sumRange = function(i, j) {
    return this.sums[j] - this.sums[i] + this.nums[j];
};


/**
 * Your NumArray object will be instantiated and called as such:
 * var numArray = new NumArray(nums);
 * numArray.sumRange(0, 1);
 * numArray.sumRange(0, 2);
 */
