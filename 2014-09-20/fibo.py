a = [1, 1]
i = 2
limit = 1000000
while (i <= limit):
    a.append(0)
    a[i] = a[i-1] + a[i-2]
    i = i + 1
"""
DON'T GO BEYOND 1 mil.
1,000,000: 8.9GB
100,000: 343MB
10,000: unnoticeable
"""
