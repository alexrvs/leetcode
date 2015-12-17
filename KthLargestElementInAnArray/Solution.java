class Solution {
    private void heapify(int[] heap, int k) {
        for (int i = k - 1; i >= 0; i--) {
            int r = (i - 1) / 2;
            if (heap[r] > heap[i]) {
                int tmp = heap[r];
                heap[r] = heap[i];
                heap[i] = tmp;
            }
        }
        return;
    }

    public int findKthLargest(int[] nums, int k) {
        int tmp = 0;
        heapify(nums, k);
        for (int i = k; i < nums.length; i++) {
            if (nums[i] > nums[0]) {
                tmp = nums[i];
                nums[i] = nums[0];
                nums[0] = tmp;
                heapify(nums, k);
            }
        }
        return nums[0];
    }
}
