public class NumArray {
    private int[] sums;
    private int[] nums;

    public NumArray(int[] nums) {
        this.nums = nums;
        int size = nums.length;
        this.sums = new int[size];
        for (int i = 1; i < size; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
    }

    public int sumRange(int i, int j) {
        return sums[j] - sums[i] + nums[j];
    }
}


// Your NumArray object will be instantiated and called as such:
// NumArray numArray = new NumArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
