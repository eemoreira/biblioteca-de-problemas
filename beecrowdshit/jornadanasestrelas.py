v = []
n = int(input())
soma = 0
v = list(map(int, input().split()))
roubados = 0
atacados = 0
zeros = 0

for i in range(n):
    soma += v[i]
if len(v) <= n:
    for i in range(n):
        if v[i] % 2 != 0 or v[i] == 0:
            roubados += 1
            atacados += 1
            v[i] -= 1
            
        else:
            roubados += i + 1
            atacados += 1
            for i in range(n):
                if v[i] <= 0:
                    zeros += 1
            for j in range(i,0, -1):
                v[j] -= 1
            break


print(f"{atacados} {soma +zeros -roubados}")
