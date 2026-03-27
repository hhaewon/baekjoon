import sys
from fractions import Fraction

input = sys.stdin.readline



def contract(r):
    i = len(r)-1
    result = Fraction(r[i], 1)
    i-=1
    while (i >= 0):
        result = Fraction(r[i], 1)+(1/result)
        i-= 1
    return result

def expand(x:Fraction):
    a = x.numerator
    b = x.denominator

    if (b == 1):
        return [a//b]

    result = []
    while  a % b != 1:
        result.append(a // b)
        temp = b
        b = a % b
        a = temp
    result.append(a // b)
    result.append(b)
    return result
    
        


def solve(n1, n2):
    r1 = list(map(int, input().split()))
    r2 = list(map(int, input().split()))

    temp1 = contract(r1)
    temp2 = contract(r2)
    plusresult = expand(temp1 + temp2)
    minusresult = expand(temp1 - temp2)
    mulresult = expand(temp1 * temp2)
    divideresult = expand(temp1 / temp2)

    for x in plusresult:
        print(x, end=" ")
    print()
    for x in minusresult:
        print(x, end=" ")
    print()
    for x in mulresult:
        print(x, end=" ")
    print()
    for x in divideresult:
        print(x, end=" ")
    print()




def main():
    n1, n2 = map(int, input().split())
    
    i = 1
    while n1 != 0 and n2 != 0:
        print(f"Case {i}:")
        solve(n1, n2)
        n1, n2 = map(int, input().split())
        i += 1
    

main()