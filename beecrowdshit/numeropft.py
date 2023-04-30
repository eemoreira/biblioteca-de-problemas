n = int(input())
v = []
divisores = []
soma = 0
for i in range(n):
    v.append(int(input()))
    for j in range(1, v[i]):
        if v[i] % j == 0:
            divisores.append(j)
        for k in range(len(divisores)):
            soma += divisores[k]
            if soma == v[i]:
                print("%d eh um numero perfeito" %v[i])         

print(divisores)

