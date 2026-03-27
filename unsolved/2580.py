row = [[0] * 10 for _ in range(9)]
col = [[0] * 10 for _ in range(9)]
small = [[[0] * 10 for i in range(3)] for j in range(3)]
board = [[0] * 9 for _ in range(9)]

for i in range(9):
    arr = list(map(int, input().split()))
    for j in range(9):
        row[i][arr[j]] = 1
        col[j][arr[j]] = 1
        small[i//3][j//3][arr[j]] = 1
        board[i][j] = arr[j]

end = False

def go(x, y):
    global end
    if x == 9:
        end = True
        return

    if board[x][y]:
        if (y != 8):
            go(x, y+1)
        else:
            go(x+1, 0)
        return

    for k in range(1, 10):
        if (row[x][k] or col[y][k] or small[x//3][y//3][k]):
            continue
        row[x][k] = 1
        col[y][k] = 1
        small[x//3][y//3][k] = 1
        board[x][y] = k
        if (y != 8):
            go(x, y+1)
        else:
            go(x+1, 0)
        if not end:
            row[x][k] = 0
            col[y][k] = 0
            small[x//3][y//3][k] = 0
            board[x][y] = 0

go(0, 0)

for i in range(9):
    for j in range(9):
        print(board[i][j], end=" ")
    print()