class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l = len(height)
        i = 0
        j = l - 1
        area = 0
        max = 0
        while i < j:
            h = height[i]
            if height[i] > height[j]:
                h = height[j]
            area = h * (j - i)
            if area > max:
                max = area
            if height[i] < height[j]:
                i += 1
            else:
                j -= 1
        return max
