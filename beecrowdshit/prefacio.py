
a,b = map(int, input().split())
q = a // b
r = a % b

if r < 0:
    q += 1
    r = a - (q*b)

print(f"{q} {r}")