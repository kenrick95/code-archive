T = int(input())
for i in range(T):
	N = int(input())
	S = []
	Map = []
	for j in range(N):
		S.append(input())
		Map.append([x for x in S[j]])
	#print(Map)
	
	su_1 = 0
	Zap = []
	for j in range(N):
		temp = []
		for k in range(N):
			if Map[j][k] == '#':
				temp.append(1)
				su_1 += 1
			else:
				temp.append(0)
		Zap.append(temp)
	#print(Zap)
	
	
	
	yeah = False
	for y1 in range(N):
		for x1 in range(N):
			for z in range(N):
				x2 = x1 + z
				y2 = y1 + z
				su  = 0
				#print(y1, x1, '  ', y2, x2)
				for j in range(y1, min(y2+1,N)):
					for k in range(x1, min(x2+1,N)):
						su += Zap[j][k]
				if (su == (z+1)*(z+1)) and (su == su_1):
					yeah = True
					break
			if yeah:
				break
		if yeah:
			break
	print("Case #", i+1, ': ', sep='', end='')
	if yeah:
		print("YES")
	else:
		print("NO")
