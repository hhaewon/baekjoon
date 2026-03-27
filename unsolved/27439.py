N = int(input())

def solve():  
    if N == 1:
        print(1)
        return 
    result = 1
    for i in range(2, N+1):
        result *= i
    print(result)

solve()
    
