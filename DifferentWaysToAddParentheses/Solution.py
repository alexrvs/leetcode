class Solution(object):
    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        if input.isdigit():
            return [int(input)]
        res = []
        for i in range(0, len(input)):
            op = input[i]
            if op in "+-*":
                left = self.diffWaysToCompute(input[:i])
                right = self.diffWaysToCompute(input[i+1:])
                for j in left:
                    for k in right:
                        if op == '+':
                            res += (j + k),
                        elif op == '-':
                            res += (j - k),
                        elif op == '*':
                            res += (j * k),
        return res
