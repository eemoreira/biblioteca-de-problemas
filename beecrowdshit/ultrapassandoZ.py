x = 0
v = []
z = 0

x = int(input())
v.append(x)

while x >= z:
    z = int(input())
    v.append(z)

maiorx = v[0]
for i in range(len(v)):
    if v[i] > maiorx and v[i] != z:
        maiorx = v[i]

w = []
soma = 0
i = 0
while soma < z:
    soma += maiorx + i 
    w.append(soma)
    i += 1
       
print(len(w))