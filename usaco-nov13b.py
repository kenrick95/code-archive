import math

myFile = open("nocow.in", "r")

f_str = myFile.readline()
f = f_str.split()
N = int(f[0])
K = int(f[1])
K -= 1

lidic = dict()
dic = dict()
sth = list()
nocow = list()

for i in range(N):
	st =  myFile.readline()
	st_p = st.split()
	# process [4:-1]
	idx = 0
	for adj in st_p[4:-1]:
		idx += 1
		#if (i == 1):
		#	lidic[idx] = []
		if (not (adj in dic)):
			dic[adj] = idx
			if (not (idx in lidic)):
				lidic[idx] = [adj]
			else:
				lidic[idx].append(adj)
	nocow.append(list(st_p[4:-1]))

#print(nocow)

adj_num = len(st_p[4:-1])
	
#print(dic)
#print(lidic)

valu = dict()

num_cows = 0
for i in range(1,adj_num+1):
	if i==1:
		num_cows = len(lidic[i])
	else:
		num_cows *= len(lidic[i])
	lidic[i].sort()
	valu[i] = len(lidic[i])


#print(num_cows)
#print(lidic)

nocow_val = dict() #decodes to values
nocow_value = list()
for i in range(len(nocow)):
	nocow_val[i] = []
	for j in range(1, adj_num+1):
		nocow_val[i].append(lidic[j].index(nocow[i][j-1]))
#print(nocow_val)
for i in nocow_val.keys():
	res = 0
	for j in range(adj_num, 0, -1):
		res += valu[j] * nocow_val[i][j-1]
	#print(res)
	nocow_value.append(res)
	if (res < K):
		K += 1

temp_k = K
i = adj_num+1
dig = list()
while temp_k > 0:
	i -= 1
	#print(temp_k, ' ', valu[i])
	dig.append(temp_k % valu[i])
	temp_k = math.floor(temp_k / valu[i])
	#print(temp_k, ' ', valu[i],' ', i)
	#print(dig)


#print(dig)

dig.reverse()
myFile.close()
myFile = open("nocow.out", "w")

for i in range(1, adj_num+1):
	myFile.write(lidic[i][dig[i-1]])
	if i != adj_num:
		myFile.write(' ')
	else:
		myFile.write('\n')
	
	#print(lidic[i][dig[i-1]],end='')
	#if i != adj_num:
	#	print(' ',end='')
	#else
	#	print()
myFile.close()
