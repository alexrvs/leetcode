class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        res = []
        l1 = len(nums1)
        l2 = len(nums2)
        i = 0
        j = 0
        list.sort(nums1)
        list.sort(nums2)
        while i < l1 and j < l2:
            print i, j
            if nums1[i] == nums2[j]:
                res.append(nums1[i])
                i += 1
                while i < l1 and nums1[i] == nums1[i - 1]:
                    i += 1
                j += 1
                while j < l2 and nums2[j] == nums2[j - 1]:
                    j += 1
            elif nums1[i] < nums2[j]:
                i += 1
                while i < l1 and nums1[i] == nums1[i - 1]:
                    i += 1
            else:
                j += 1
                while j < l2 and nums2[j] == nums2[j - 1]:
                    j += 1
        return res
