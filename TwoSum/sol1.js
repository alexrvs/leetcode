/**
 *
 *  * @param {number[]} nums
 *
 *   * @param {number} target
 *
 *    * @return {number[]}
 *
 *     */

var twoSum = function(nums, target) {
    numMap = new Map();
    for (var i = 0; i < nums.length; i++) {
      lookup = target - nums[i];
      if ( numMap.has(lookup) ) {
        return [numMap.get(lookup)+1, i+1];
      }
      numMap.set(nums[i], i);
    }
};
