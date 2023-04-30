v = []
m = 1
n = 1
soma = 0


while m > 0 and n > 0:

    m, n = map(int, input().split())
    if m > 0 and n > 0:
        if m > n: 
            for i in range(n, m+1):
                v.append(i)
        if n >= m:
            for i in range(m, n+1):
                v.append(i)
        
        for i in range(len(v)):
            soma += v[i]
        v.append("Sum=%d" %soma)
        print(*v)
        v = []
        soma = 0


