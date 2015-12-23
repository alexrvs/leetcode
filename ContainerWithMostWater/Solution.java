public class Solution {
    public int maxArea(int[] height) {
        int i = 0;
        int j = height.length - 1;
        int max = 0;
        int area = 0;
        int h = 0;
        while (i < j) {
            h = height[i] < height[j] ? height[i] : height[j];
            area = h * (j - i);
            max = max > area ? max : area;
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return max;
    }
}
