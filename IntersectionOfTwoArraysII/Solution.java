public class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        int l1 = nums1.length;
        int l2 = nums2.length;
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        List<Integer> res = new ArrayList<Integer>();
        for (int i = 0, j = 0; i < l1 && j < l2; ) {
            if (nums1[i] == nums2[j]) {
                res.add(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        int[] nums = new int[res.size()];
        for (int i = 0; i < res.size(); i++) {
            nums[i] = res.get(i);
        }
        return nums;
    }
}
