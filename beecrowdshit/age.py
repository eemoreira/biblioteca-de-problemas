age = int(input())
agebla = ""
if (age // 365) >= 0:
    agebla = agebla + ("%d ano(s)\n" %(age//365))
if ((age % 365) // 30) >= 0:
    agebla = agebla + ("%d mes(es)\n" %((age %365) // 30 ))
if (((age % 365) % 30)) >= 0:
    agebla = agebla + ("%d dia(s)" %((age %365) % 30))
print(agebla)