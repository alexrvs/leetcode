var heapify = function(heap, k) {
    for (var i = k - 1; i > 0; i--) {
        var r = Math.floor((i - 1) / 2);
        if (heap[r] > heap[i]) {
            var tmp = heap[r];
            heap[r] = heap[i];
            heap[i] = tmp;
        }
    }
}

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findKthLargest = function(nums, k) {
    heapify(nums, k);
    for (var i = k; i < nums.length; i++) {
        if (nums[i] > nums[0]) {
            var tmp = nums[i];
            nums[i] = nums[0];
            nums[0] = tmp;
            heapify(nums, k);
        }
    }
    return nums[0];
};
