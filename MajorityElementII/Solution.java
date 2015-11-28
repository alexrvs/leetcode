public class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int size = nums.length;
        int num1, num2, cnt1, cnt2;
        num1 = num2 = cnt1 = cnt2 = 0;
        for (int i = 0; i < size; i++) {
            if (cnt1 > 0 && nums[i] == num1) { cnt1++; continue; }
            if (cnt2 > 0 && nums[i] == num2) { cnt2++; continue; }
            if (cnt1 == 0) { num1 = nums[i]; cnt1++; continue; }
            if (cnt2 == 0) { num2 = nums[i]; cnt2++; continue; }
            cnt1--; cnt2--;
        }
        if (cnt1 > 0) {
            cnt1 = 0;
            for (int i = 0; i < size; i++) {
                if (nums[i] == num1) cnt1++;
            }
        }
        if (cnt2 > 0) {
            cnt2 = 0;
            for (int i = 0; i < size; i++) {
                if (nums[i] == num2) cnt2++;
            }
        }
        List<Integer> res = new ArrayList<Integer>();
        if (cnt1 > size / 3) res.add(num1);
        if (cnt2 > size / 3) res.add(num2);
        return res;
    }
}
