n = int(input())
fib = [0, 1]
somafib = int

for i in range(n):
    m = int(input())
    if m == 0:
        print("Fib(0) = 0")
    elif m == 1:
        print("Fib(1) = 1")
    else:
        for j in range(m):
            somafib = fib[j] + fib[j+1]
            fib.append(somafib)
        print(f"Fib({len(fib)-2}) = {fib[m]}")
        fib = [0, 1]