class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int xSize = x.size();
        if (xSize < 4) return 0;
        int i = 2;
        while (i < xSize && x[i] > x[i - 2]) i++;
        if (i > 2 && x[i] >= x[i - 2] - (i == 3 ? 0 : x[i - 4])) x[i - 1] -= x[i - 3];
        i++;
        while (i < xSize && x[i] < x[i - 2]) i++;
        return i < xSize;
    }
};