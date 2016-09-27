a, b = map(str, input().split())
ans = 0
for ia in a:
    for ib in b:
        ans += int(ia) * int(ib)
print(ans)
