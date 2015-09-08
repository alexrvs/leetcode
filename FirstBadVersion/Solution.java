/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        int m = 0;
        do {
            m = (r - l) / 2 + l;
            if (isBadVersion(m)) {
                r = m;
            } else {
                l = m + 1;
            }
        } while (l < r);
        return r;
    }
}
