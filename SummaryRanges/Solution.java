public class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> ranges = new ArrayList<String>();
        int size = nums.length;
        if (size == 0) return ranges;
        int start = nums[0];
        String range = "";
        for (int i = 1; i < size; i++) {
            if (nums[i] != nums[i-1] + 1) {
                range = "";
                if (nums[i-1] == start) {
                    range += start;
                } else {
                    range += start + "->" + nums[i-1];
                }
                start = nums[i];
                ranges.add(range);
            }
        }
        range = "";
        if (nums[size-1] == start) {
            range += start;
        } else {
            range += start + "->" + nums[size-1];
        }
        ranges.add(range);
        return ranges;
    }
}
