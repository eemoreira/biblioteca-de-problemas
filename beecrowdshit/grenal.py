n = 0
m = 0
gremio = 0
inter = 0
jogos = 0
empates = 0

while n != 2:
    golint, golgre = map(int, input().split())
    print("Novo grenal (1-sim 2-nao)")
    n = int(input())
    if golgre > golint:
        gremio += 1
    elif golgre < golint:
        inter += 1
    else:
        empates += 1
    jogos += 1

print("%d grenais" %jogos)
print("Inter:%d" %inter)
print("Gremio:%d" %gremio)
print("Empates:%d" %empates)
if gremio > inter:
    print("Gremio venceu mais")
elif inter > gremio:
    print("Inter venceu mais")
else:
    print("Nao houve vencedor")