class Solution(object):
    def __init__(self):
        self.digits = "123456789"

    def isValid(self, board, a, b):
        r = len(board)
        if r == 0:
            return False
        c = len(board[0])
        for i in range(0, r):
            if i != a and board[i][b] == board[a][b]:
                return False
        for j in range(0, c):
            if j != b and board[a][j] == board[a][b]:
                return False
        x = a // 3 * 3
        y = b // 3 * 3
        for i in range(0, 3):
            for j in range(0, 3):
                if x + i != a and y + j != b and board[x + i][y + j] == board[a][b]:
                    return False
        return True
        
    def dfs(self, board):
        r = len(board)
        if r == 0:
            return False
        c = len(board[0])
        for i in range(0, r):
            for j in range(0, c):
                if board[i][j] == '.':
                    for c in range(0, 9):
                        board[i][j] = self.digits[c]
                        if self.isValid(board, i, j) and self.dfs(board):
                            return True
                        board[i][j] = '.'
                    return False
        return True
        
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        self.dfs(board)
