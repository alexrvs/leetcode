class Solution {
    public:
        int searchInsert(int A[], int n, int target) {
            int l = 0;
            int r = n;
            while (l < r)
            {
                int mid = l+(r-l)/2;
                if (A[mid] >= target)//find the left most target
                    r = mid-1;
                else if (A[mid] < target)
                    l = mid+1;
            }
            return l;
        }
};
