class Queue(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.a = []
        self.b = []

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.a.append(x)

    def pop(self):
        """
        :rtype: nothing
        """
        x = self.peek()
        if x != None:
            self.b.pop()
        return

    def peek(self):
        """
        :rtype: int
        """
        if self.empty() == True:
            return None
        bl = len(self.b)
        if bl == 0:
            al = len(self.a)
            while al > 0:
                self.b.append(self.a.pop())
                al -= 1
        return self.b[-1]

    def empty(self):
        """
        :rtype: bool
        """
        al = len(self.a)
        bl = len(self.b)
        return (al == 0 and bl == 0)
