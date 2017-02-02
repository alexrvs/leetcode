public class Solution {
    public boolean find132pattern(int[] nums) {
        int size = nums.length;
        Stack<Integer> largers = new Stack<Integer>();
        int s3 = Integer.MIN_VALUE;
        for (int i = size - 1; i >= 0; i--) {
            if (nums[i] < s3) {
                return true;
            } else {
                while (0 != largers.size() && largers.peek() < nums[i]) {
                    s3 = largers.peek();
                    largers.pop();
                }
            }
            largers.push(nums[i]);
        }
        return false;
    }
}