// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        int m = 0;
        do {
            m = (r-l)/2+l;
            if (isBadVersion(m)) {
                r = m;
            } else {
                l = m+1;
            }
        } while (l < r);
        return r;
    }
};
