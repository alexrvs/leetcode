class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        l = len(gas)
        start = -1
        tank = 0
        for i in list(range(0, 2*l)):
            cur = i%l
            if cur == start:
                return start
            tank += gas[cur] - cost[cur]
            if tank >= 0:
                if start == -1:
                    start = cur
            else:
                start = -1
                tank = 0
        return -1
