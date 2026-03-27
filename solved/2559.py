N, K = map(int, input().split())

arr = list(map(int, input().split()))

partialSum = 0
maxS = 0

for i in range(K):
    partialSum += arr[i]

maxS = partialSum

for i in range(N - K):
    maxS = max(maxS, partialSum + arr[K + i] - arr[i])
    partialSum = partialSum + arr[K + i] - arr[i]
print(maxS)
