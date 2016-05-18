class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                do { i++; } while (nums1[i] == nums1[i - 1]);
                do { j++; } while (nums2[j] == nums2[j - 1]);
            } else if (nums1[i] < nums2[j]) {
                do { i++; } while (nums1[i] == nums1[i - 1]);
            } else {
                do { j++; } while (nums2[j] == nums2[j - 1]);
            }
        }
        return res;
    }
};
