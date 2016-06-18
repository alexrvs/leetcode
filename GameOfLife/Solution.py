class Solution(object):
    def isLive(self, board, i, j, row, col):
        cnt = 0
        for r in range(-1, 2):
            for c in range(-1, 2):
                if r == 0 and c == 0:
                    continue
                if i + r >= 0 and i + r < row and \
                   j + c >= 0 and j + c < col and \
                   board[i + r][j + c] & 0x0001 == 1:
                       cnt += 1
        if cnt == 2 and board[i][j] == 1:
            return True
        if cnt == 3:
            return True
        return False

    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        r = len(board)
        if r == 0:
            return
        c = len(board[0])
        for i in range(0, r):
            for j in range(0, c):
                if True == self.isLive(board, i, j, r, c):
                    board[i][j] += 2
        for i in range(0, r):
            for j in range(0, c):
                board[i][j] >>= 1
        return
