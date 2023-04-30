n = int(input())
m = []
for i in range(n):
    m.append([float(num) for num in input().split(" ", 1)])
    print
min = m[0][0]/m[0][1]

for i in range (1,n):
    if (min > m[i][0]/m[i][1]):
        min = m[i][0]/m[i][1]

valor = min*1000
print("%.2f" % valor)