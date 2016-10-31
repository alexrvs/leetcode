class Solution {
public:
    int arrangeCoins(int n) {
        int layer = 1;
        while (n >= layer) {
            n -= layer;
            layer++;
        }
        return layer - 1;
    }
};