T = int(input())
n = int(input())
A = list(map(int, input().split()))
m = int(input())
B = list(map(int, input().split()))

result = 0
# A[i]~A[j], B[p]~B[q]
def solve(i, j, p, q):
