public class Solution {
    public int trap(int[] height) {
        int size = height.length;
        int[] forward = new int[size];
        int[] backward = new int[size];
        int maxH = 0;
        for (int i = 0; i < size; i++) {
            if (maxH < height[i]) maxH = height[i];
            forward[i] = maxH - height[i];
        }
        maxH = 0;
        int sum = 0;
        for (int i = size - 1; i >= 0; i--) {
            if (maxH < height[i]) maxH = height[i];
            backward[i] = maxH - height[i];
            sum += (forward[i] < backward[i] ? forward[i] : backward[i]);
        }
        return sum;
    }
}
