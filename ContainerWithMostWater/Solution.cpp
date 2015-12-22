class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int size = height.size();
        int area = 0;
        int h = 0;
        int i = 0;
        int j = size - 1;
        while (i < j) {
            h = height[i] < height[j] ? height[i] : height[j];
            area = h * (j - i);
            if (area > max) {
                max = area;
            }
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return max;
    }
};
