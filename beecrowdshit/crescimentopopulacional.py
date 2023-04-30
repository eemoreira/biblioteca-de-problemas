n = int(input())
v = []
for i in range(n):
  pa,pb,ca,cb = map(float, input().split())
  pa = int(pa)
  pb = int(pb)
  if pb > pa:
    while pb >= pa:
      pa += int(pa*ca/100)
      pb += int(pb*cb/100)
      v.append(pa)
      if len(v) > 100:
          break
    if len(v) > 100:
      print("Mais de 1 seculo.")
    else:
        print(f"{len(v)} anos.")
    v = []