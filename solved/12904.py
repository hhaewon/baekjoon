S = input()
T = input()

start = 0
end = len(T)-1
flipped = False
length = len(T)

for i in range(len(T)-len(S)):
    if not flipped:
        if T[end] == 'A':
            end -= 1
        else:
            flipped = True
            end -= 1
    else:
        if T[start] == 'A':
            start += 1
        else:
            flipped = False
            start += 1
            
result = True

if not flipped:
    for i in range(len(S)):
        if S[i] != T[start+i]:
            result = False
            break
else:
    for i in range(len(S)):
        if S[i] != T[end-i]:
            result = False
            break

print(int(result))
            