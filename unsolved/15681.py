import sys
sys.setrecursionlimit(10*8)

def makeTree(current, parent):
    visited[current] = True
    for node in adjoin[current]:
        if node != parent and not visited[node]:
            childrens[current].append(node)
            makeTree(node, current)

def countSubtreeNodes(current):
    size[current] = 1
    for node in childrens[current]:
        countSubtreeNodes(node)
        size[current] += size[node]

N, R, Q = map(int, input().split())

adjoin = [[] for _ in range(N+1)]
size = [0] * (N+1)
childrens = [[] for _ in range(N+1)]
visited = [False] * (N+1)

for _ in range(N-1):
    U, V = map(int, input().split())
    adjoin[U].append(V)
    adjoin[V].append(U)

makeTree(R, -1)
countSubtreeNodes(R)

for _ in range(Q):
    U = int(input())
    print(size[U])