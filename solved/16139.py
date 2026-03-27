str = input()
q = int(input())

s = [[0] * 200001 for _ in range(26)]  # s[i][j+1] : 0<=k<=j중 'a'+i개수


for j in range(0, len(str)):
    index = ord(str[j]) - ord("a")
    for i in range(26):
        if index == i:
            s[i][j + 1] = s[i][j] + 1
        else:
            s[i][j + 1] = s[i][j]

for _ in range(q):
    a, left, right = input().split()
    left = int(left)
    right = int(right)
    index = ord(a) - ord("a")
    print(s[index][right + 1] - s[index][left])
