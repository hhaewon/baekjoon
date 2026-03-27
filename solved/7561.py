def det(A):
    return A[1][1]*(A[2][2]*A[3][3]-A[2][3]*A[3][2])-A[1][2]*(A[2][1]*A[3][3]-A[2][3]*A[3][1])+A[1][3]*(A[2][1]*A[3][2]-A[2][2]*A[3][1])

T = int(input())
A = [[0]*4 for _ in range(4)]
tempA =  [[0]*4 for _ in range(4)]
detAs = [0, 0, 0, 0]
b = [0, 0, 0, 0]

for _ in range(T):
    for i in range(1, 4):
        a1, a2, a3, b1 = map(int, input().split())
        A[i][1], A[i][2], A[i][3] = a1, a2, a3
        tempA[i][1], tempA[i][2], tempA[i][3] = a1, a2, a3
        b[i] = b1
    
    detA = det(A)
    for i in range(1, 4):
        tempA[1][i], tempA[2][i], tempA[3][i] = b[1], b[2], b[3]
        detAs[i] = det(tempA)
        tempA[1][i], tempA[2][i], tempA[3][i] = A[1][i], A[2][i], A[3][i]

        
    print(detAs[1], detAs[2], detAs[3], detA)
    if detA == 0:
        print("No unique solution\n")
        continue

    x1 = detAs[1]/detA
    x2 = detAs[2]/detA
    x3 = detAs[3]/detA
    print(f"Unique solution: {x1+0:.3f} {x2+0:.3f} {x3+0:.3f}\n")
