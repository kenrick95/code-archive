f1 = open("f1.txt", "r")
f2 = open("f2.txt", "r")
r1 = f1.read()
r2 = f2.read()
f1.close()
f2.close()

def enc(st):
    d = dict()
    for i in range(len(st)):
        if (st[i].lower() in d):
            d[st[i].lower()] += 1
        else:
            d[st[i].lower()] = 1
    return d
    
d1 = enc(r1)
d2 = enc(r2)

print(d1)
print(d2)

for i in d1.keys():
    print(i, ' ', d1[i]/d2[i])
