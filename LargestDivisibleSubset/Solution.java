public class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int size = nums.length;
        Arrays.sort(nums);
        int[] steps = new int[size];
        int[] idx = new int[size];
        int maxIdx = 0;
        int maxStep = 0;
        for (int i = 0; i < size; i++) {
            steps[i] = 1;
            idx[i] = i;
            if (steps[i] > maxStep) {
                maxStep = steps[i];
                maxIdx = i;
            }
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0) {
                    steps[i] = steps[j] + 1;
                    idx[i] = j;
                    if (steps[i] > maxStep) {
                        maxStep = steps[i];
                        maxIdx = i;
                    }
                    break;
                }
            }
        }
        Integer[] res = new Integer[maxStep];
        while (maxStep-- != 0) {
            res[maxStep] = nums[maxIdx];
            maxIdx = idx[maxIdx];
        }
        return Arrays.asList(res);
    }
}
