dimensao = int(input())
v = []
w =[]
for i in range(dimensao):
    l1,l2,l3 = map(int, input().split())
    if l1 != 0 and l2 != 0 and l3 != 0:
        soma = l1 + l2 + l3
    w.append(l1)
    w.append(l2)
    w.append(l3)
    v.append(w)
    w = []

for i in range(dimensao):
    for j in range(dimensao):
        if v[i][j] == 0:
            posicaoi = i
            posicaoj = j
soma2 = 0
for j in range(len(v)):
    soma2 += v[posicaoi][j]

valorindecifravel = soma - soma2
print(v)
print(valorindecifravel)
print(posicaoi + 1)
print(posicaoj + 1)

