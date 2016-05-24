public class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        int l1 = nums1.length;
        int l2 = nums2.length;
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        List<Integer> res = new ArrayList<Integer>();
        for (int i = 0, j = 0; i < l1 && j < l2; ) {
            if (nums1[i] == nums2[j]) {
                res.add(nums1[i]);
                while ( ++i < l1 && nums1[i] == nums1[i - 1]);
                while ( ++j < l2 && nums2[j] == nums2[j - 1]);
            } else if (nums1[i] < nums2[j]) {
                while ( ++i < l1 && nums1[i] == nums1[i - 1]);
            } else {
                while ( ++j < l2 && nums2[j] == nums2[j - 1]);
            }
        }
        int[] nums = new int[res.size()];
        for (int i = 0; i < res.size(); i++) {
            nums[i] = res.get(i);
        }
        return nums;
    }
}
