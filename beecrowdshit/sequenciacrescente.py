n = int
v = []
m = 1
w = []
while n != 0:
    n = int(input())
    v.append(n)

for i in range(len(v) - 1):
    while m != v[i] + 1:
        w.append(m)
        m += 1
    print(*w)


    m = 1
    w = []
