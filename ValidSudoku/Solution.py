class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        l = len(board)
        rowNums = [ 0 ] * l
        colNums = [ 0 ] * l
        gridNums = [ 0 ] * l
        for i in range(0, l):
            for j in range(0, l):
                g = (i // 3) * 3 + j // 3
                if board[i][j] != '.':
                    val = 1 << (int(board[i][j]) - 1)
                    if (rowNums[i] & val) != 0 or (colNums[j] & val) != 0 or (gridNums[g] & val) != 0:
                        return False
                    else:
                        rowNums[i] |= val
                        colNums[j] |= val
                        gridNums[g] |= val
        return True
