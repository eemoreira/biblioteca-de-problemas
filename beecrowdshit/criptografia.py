tamanho, linhas = map(int, input().split())

v = list(map(str, input()))
w = list(map(str, input()))

if len(v) == tamanho and len(w) == tamanho:

    for i in range(linhas):
        frase = list(map(str, input()))
        for k in range(tamanho):
            for j in range(len(frase)):
                if frase[j] == v[k] and frase[j].isupper():
                    frase[j] = w[k].upper()
                elif frase[j] == v[k].lower():
                    frase[j] = w[k].lower()
                elif frase[j] == w[k] and frase[j].isupper():
                    frase[j] = v[k].upper()
                elif frase[j] == w[k].lower():
                    frase[j] = v[k].lower()
        print("".join(frase))

