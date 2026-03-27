S = input()
T = input()

slen = len(S)

def possible(start, end, flip):
    if (end-start+1 == slen):
        if (not flip):
            for i in range(slen):
                if S[i] != T[start+i]:
                    return False
        else:
            for i in range(slen):
                if S[i] != T[end-i]:
                    return False
        return True
    
    if not flip:
        if (T[end] == 'A' and T[start] == 'B'):
            return possible(start, end-1, False) or possible(start+1, end, True)
        elif (T[end] == 'A' and T[start] != 'B'):
            return possible(start, end-1, False)
        elif T[end] != 'A' and T[start] == 'B':
            return possible(start+1, end, True)
        else:
            return False
    else:
        if (T[start] == 'A' and T[end] == 'B'):
            return possible(start+1, end, True) or possible(start, end-1, False)
        elif T[start] == 'A' and T[end] != 'B':
            return possible(start+1, end, True)
        elif T[start] != 'A' and T[end] == 'B':
            return possible(start, end-1, False)
        else:
            return False
        
print(int(possible(0, len(T)-1, False)))