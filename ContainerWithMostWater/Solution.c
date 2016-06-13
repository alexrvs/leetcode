int maxArea(int* height, int heightSize) {
    int max = 0;
    int l = 0;
    int r = heightSize - 1;
    int area = 0;
    int h = 0;
    while (l < r) {
        h = height[l] < height[r] ? height[l] : height[r];
        area = h * (r - l);
        max = max < area ? area : max;
        if (height[l] < height[r]) l++;
        else r--;
    }
    return max;
}
