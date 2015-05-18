n = int(input())
b = []
i = 0
while (i < n):
    b.append(int(input()))
    i += 1
a = [[] for x in range(300)]

def f(i):
    while (b[i] > 0):
        if (b[i] > 9):
            a[i].append(9)
            b[i] -= 9
        else:
            a[i].append(b[i])
            b[i] -= b[i]
    a[i].reverse()
    return a[i]
def aToInt(i):
    return int("".join(map(str, [x for x in a[i]])))

cur_min = f(0)
cur_min_val = aToInt(0)
print(cur_min_val)

i = 1
while (i < n):
    cur_seq = f(i)
    cur_val = aToInt(i)
    while (cur_val <= cur_min_val):
        if (len(cur_seq) < len(cur_min)):
            cur_seq[0] -= 1
            cur_seq.insert(0, 1)
        elif (len(cur_seq) == len(cur_min)):
            if (cur_seq[0] == 1 or len(cur_seq) == 1):
                if (cur_min[0] == 1):
                    cur_seq[len(cur_seq) - 1] -= 1
                    cur_seq[0] += 1
                else:
                    cur_seq[0] -= 1
                    cur_seq.insert(0, 1)
            else:
                cur_seq[len(cur_seq) - 1] -= 1
                cur_seq[0] += 1
        a[i] = cur_seq
        cur_val = aToInt(i)
        
    cur_val = aToInt(i)
    print(cur_val)
    cur_min = cur_seq
    cur_min_val = cur_val
    i += 1
