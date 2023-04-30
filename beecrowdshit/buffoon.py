nop = int(input())
v = []
bla = 0

for i in range(nop):
    a = int(input())
    v.append(a)
for i in range(1,nop):
    if (v[0] >= v[i]):
        bla += 1
    else:
        break
if bla == (nop-1):
    print("S")
else:
    print("N")
