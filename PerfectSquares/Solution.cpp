class Solution {
public:
    int numSquares(int n) {
        vector<int> nums(n+1, 0);
        int least = 0;
        int num = 0;
        for (int i = 1; i <= n; i++) {
            least = i;
            for (int x = 1; x * x <= i; x++) {
                num = 1 + nums[ i - x * x ];
                if (least > num) {
                    least = num;
                }
            }
            nums[i] = least;
        }
        return nums[n];
    }
};
