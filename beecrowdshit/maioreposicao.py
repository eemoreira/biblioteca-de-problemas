v = []
maior = 0
posicao = 1

for i in range(100):
    v.append(int(input()))
    if (v[i] > maior):
        maior = v[i]
    
print(maior)

for i in range(100):
    if v[i] != maior:
        posicao += 1
    else:
        break

print(posicao)