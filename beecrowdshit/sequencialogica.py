n = int(input())
m = 0
m2 = 0
m3 = 0

for i in range(1,n+1):
    m = i
    m2 = i*i
    m3 = i*i*i
    print(m, m2, m3)
    print(m, m2+1, m3+1)