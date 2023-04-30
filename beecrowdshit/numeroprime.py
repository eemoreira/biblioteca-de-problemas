n = int(input())
notprimenumber = 0
v = []

for i in range(n):
    v.append(int(input()))
    for j in range(2, v[i] - 1):
        if v[i] % j == 0:
            notprimenumber += 1
    if notprimenumber > 0:
        print("%d nao eh primo" %v[i])
        notprimenumber = 0
    else:
        print("%d eh primo" %v[i])