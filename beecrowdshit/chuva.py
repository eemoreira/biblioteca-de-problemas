tamanho = int(input())
soma = int(input())
v = []
for i in range(tamanho):
    v.append(int(input()))

w = []

for i in range(tamanho):
    for j in range(tamanho):
        w.append(v[i])