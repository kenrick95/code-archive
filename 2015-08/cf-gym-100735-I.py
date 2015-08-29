a = int(input())
b = int(input())
c = int(input())
if a + b == c or a + c == b or b + c == a \
or a + a == b or b + b == a \
or a + a == c or c + c == a \
or b + b == c or c + c == b:
    print("YES")
else:
    print("NO")