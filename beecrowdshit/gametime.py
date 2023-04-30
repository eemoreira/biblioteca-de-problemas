hi,mi,hf,mf = map(int, input().split())

mi += hi*60
mf += hf*60

tempo = mf - mi

if mi >= mf:
    tempo = 24*60 + (mf - mi)

tempohoras = tempo//60
tempominutos = tempo%60

print(f"O JOGO DUROU {tempohoras} HORA(S) E {tempominutos} MINUTO(S)")