f = open("input15.txt")
s = f.read()
cosas = s.split(",")
print(cosas)
retFinal = 0
for palabra in cosas:
    ret = 0
    for letra in palabra:
        a = 0;
        a = a+ord(letra)
        a = a * 17
        a = a % 256
        ret = ret + a
    retFinal = retFinal + ret
    print ret
print retFinal
