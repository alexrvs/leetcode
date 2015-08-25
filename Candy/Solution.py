class Solution(object):
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        candies = [1]
        l = len(ratings)
        for i in list(range(1, l)) :
            if ratings[i] > ratings[i - 1] :
                candies.append(candies[i - 1] + 1)
            else:
                candies.append(1)
        l -= 1
        for i in reversed(list(range(0, l))) :
            if ratings[i] > ratings[i + 1] :
                num = candies[i + 1] + 1
                if num > candies[i] :
                    candies[i] = num

        return sum(candies)
