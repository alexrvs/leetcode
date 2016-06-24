class Solution {
private:
    int myGCD(int x, int y) {
        return (y == 0 ? x : myGCD(y, x % y));
    }

public:
    bool canMeasureWater(int x, int y, int z) {
        if (x == 0 && y == z) return true;
        if (y == 0 && x == z) return true;
        if (x == z || y == z) return true;
        if (z > x + y) return false;
        return z % myGCD(x, y) == 0;
    }
};
