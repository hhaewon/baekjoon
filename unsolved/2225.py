dp = [[0] * 201 for _ in range(201)]

N, K = map(int, input().split())
M = 1000000000

for j in range(1, K + 1):
    dp[j][0] = 1

for i in range(1, N + 1):
    dp[1][i] = 1

for i in range(1, N + 1):
    for j in range(2, K + 1):
        for k in range(0, i + 1):
            dp[j][i] = (dp[j][i] + dp[j - 1][i - k]) % M

print(dp[K][N])
