class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m+n);
        int i1 = m - 1;
        int i2 = n - 1;
        int i = m + n - 1;
        nums1.resize(m+n);
        while (i1 >= 0 && i2 >= 0) {
            if (nums1[i1] > nums2[i2]) {
                nums1[i--] = nums1[i1--];
            } else {
                nums1[i--] = nums2[i2--];
            }
        }
        while (i2 >= 0) {
            nums1[i--] = nums2[i2--];
        }
        return;
    }
};
