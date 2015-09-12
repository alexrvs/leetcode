class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        left = []
        for i in range(0, len(s)):
            if s[i] in "([{":
                left.append(s[i])
            elif s[i] == ')':
                if len(left) > 0 and left[-1] == '(':
                    left.pop()
                else:
                    return False
            elif s[i] == ']':
                if len(left) > 0 and left[-1] == '[':
                    left.pop()
                else:
                    return False
            elif s[i] == '}':
                if len(left) > 0 and left[-1] == '{':
                    left.pop()
                else:
                    return False
        if len(left) > 0:
            return False
        return True
