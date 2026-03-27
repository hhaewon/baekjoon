import sys
from fractions import Fraction
input = sys.stdin.readline

T = int(input())
minIndex = 11
flag= False

def solve(x:Fraction, i:int, start:Fraction):
    global minIndex
    global flag
    if flag:
        return
    if i >= 11:
        return 
    subsize = Fraction(1,3)**i
    if (start + subsize < x < start + 2*subsize):
        minIndex = i;
        flag = True
        return
    
    if (start <= x <= start + subsize):
        solve(x, i+1, start)
    else:    
        solve(x, i+1, start+2*subsize)

for _ in range(T):
    a, b = map(int, input().split())
    x = Fraction(a, b)
    if (x > Fraction(1, 1)):
        print("0")
        continue
    
    solve(x, 0 , Fraction(0, 1))
    if minIndex == 11:
        minIndex = -1
    print(minIndex)
    minIndex = 11
    flag = False
