class MinStack:

    # initialize your data structure here.
    def __init__(self):
        self.elements = []
        self.minIndexes = []

    # @param x, an integer
    # @return nothing
    def push(self, x):
        self.elements.append(x)
        if len(self.minIndexes) == 0 or x < self.elements[self.minIndexes[-1]]:
            self.minIndexes.append(len(self.elements) - 1)

    # @return nothing
    def pop(self):
        if self.minIndexes[-1] == len(self.elements) - 1:
            self.minIndexes.pop()
        self.elements.pop()

    # @return an integer
    def top(self):
        return self.elements[-1]

    # @return an integer
    def getMin(self):
        return self.elements[self.minIndexes[-1]]
