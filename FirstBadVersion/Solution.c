// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int l = 1;
    int r = n;
    int m = 0;
    while(l < r) {
        m = l + (r - l) / 2;
        if (isBadVersion(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return r;
}
