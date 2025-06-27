import sys


def makeZero():
    N = int(input().rstrip('\n'))
    board = [[set() for _ in range(N + 1)] for _ in range(3)]
    board[0][0], board[1][0], board[2][0] = set([(0, '', '')]), set([(0, '', '')]), set([(0, '', '')])
    board[0][1], board[1][1], board[2][1] = set([(1, '1', '1')]), set([(1, '1', '1')]), set([(1, '1', '1')])

    for n in range(2, N + 1):
        for i in range(3):
            for tempNum, tempStr, tempAll in board[i][n - 1]:
                board[0][n].add((tempNum + n, str(n), tempAll + '+' + str(n)))
                board[1][n].add((tempNum - n, str(-n), tempAll + '-' + str(n)))
                board[2][n].add(
                    (tempNum - int(tempStr) + int(tempStr + str(n)), tempStr + str(n), tempAll + ' ' + str(n)))

    temp = [*board[0][-1], *board[1][-1], *board[2][-1]]
    temp.sort(key=lambda x: x[2])
    for a, b, c in temp:
        if a == 0:
            print(c)


def solution():
    T = int(input().rstrip('\n'))
    for t in range(T):
        makeZero()
        if t != T - 1:
            print()


input = sys.stdin.readline
solution()