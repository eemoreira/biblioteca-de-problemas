n = 4
v = [int(num) for num in input().split(" ", n-1)]
max = v[0]

for i in range(1,4):
    if (max < v[i]):
        max = v[i]
newnumber = max - 3

for i in range(len(v)):
    newnumber += v[i]
newnumber -= max

print(newnumber)