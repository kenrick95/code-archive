import json
R = 0
C = 0
S = 0
mp = []

def get_prob(r, c):
    if r < 0 or r >= R or c < 0 or c >= C:
        return 0.0
    if mp[r][c] == 'A':
        return P
    return Q

def f(r, c, s, caught):
    if r < 0 or r >= R or c < 0 or c >= C or s > S:
        return 0.0

    max_ret = 0.0
    prob = 0.
   

    if caught[r][c] == True or s == 0:
        caught_n = json.loads(json.dumps(caught))
        candidates = [
            f(r + 1, c, s + 1, caught_n),
            f(r - 1, c, s + 1, caught_n),
            f(r, c + 1, s + 1, caught_n),
            f(r, c - 1, s + 1, caught_n)
        ]

        max_ret = max(candidates)

    else:
        prob = get_prob(r, c)
        caught_y = json.loads(json.dumps(caught))
        caught_n = json.loads(json.dumps(caught))
        caught_y[r][c] = True
        candidates = [
            prob * (1. + f(r + 1, c, s + 1, caught_y)) + (1. - prob) * f(r + 1, c, s + 1, caught_n),
            prob * (1. + f(r - 1, c, s + 1, caught_y)) + (1. - prob) * f(r - 1, c, s + 1, caught_n),
            prob * (1. + f(r, c + 1, s + 1, caught_y)) + (1. - prob) * f(r, c + 1, s + 1, caught_n),
            prob * (1. + f(r, c - 1, s + 1, caught_y)) + (1. - prob) * f(r, c - 1, s + 1, caught_n)
            ]

        max_ret = max(candidates)
    
    # print(r, c, "->", [[r + 1, c], [r - 1, c], [r, c + 1], [r, c - 1]][candidates.index(max_ret)], max_ret)
    return max_ret

T = int(input())
for t in range(T):
    line = input()
    R, C, Rs, Cs, S = [int(x) for x in line.split(" ")]
    line = input()
    P, Q = [float(x) for x in line.split(" ")]
    
    mp = []
    caught = []
    for i in range(R):
        mp.append([])
        caught.append([])
        line = input()
        for v in line.split(" "):
            mp[i].append(v)
            caught[i].append(False)

    print(f(Rs, Cs, 0, caught))