public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int size = nums.length;
        if (size < 3) return 0;
        Arrays.sort(nums);
        int closest = nums[0] + nums[1] + nums[2];
        int sum = 0;
        int minDist = closest < target ? target - closest : closest - target;
        for (int i = 0; i < size - 2;) {
            for (int j = i + 1, k = size - 1; j < k; ) {
                sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    if (target - sum < minDist) {
                        minDist = target - sum;
                        closest = sum;
                    }
                    while (++j < k && nums[j] == nums[j - 1]);
                } else {
                    if (sum - target < minDist) {
                        minDist = sum - target;
                        closest = sum;
                    }
                    while (j < --k && nums[k] == nums[k + 1]);
                }
            }
            while (++i < size && nums[i] == nums[i - 1]);
        }
        return closest;
    }
}
