class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l = len(height)
        forward = [ 0 ] * l
        backward = [ 0 ] * l
        maxH = 0
        for i in range(0, l):
            if maxH < height[i]:
                maxH = height[i]
            forward[i] = maxH - height[i]
        maxH = 0
        sum = 0
        for i in range(l - 1, -1, -1):
            if maxH < height[i]:
                maxH = height[i]
            backward[i] = maxH - height[i]
            if forward[i] < backward[i]:
                sum += forward[i]
            else:
                sum += backward[i]
        return sum
