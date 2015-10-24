class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> forward(size, 0);
        vector<int> backward(size, 0);
        int max = 0;
        int sum = 0;
        for (int i = 0; i < size; i++) {
            if (max < height[i]) max = height[i];
            forward[i] = max - height[i];
        }
        max = 0;
        for (int i = size - 1; i >= 0; i--) {
            if (max < height[i]) max = height[i];
            backward[i] = max - height[i];
        }
        for (int i = 0; i < size; i++) {
            sum += (forward[i] < backward[i] ? forward[i] : backward[i]);
        }
        return sum;
    }
};
