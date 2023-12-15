

def buscaEnVector(vec, letras): 
    for i in range(vec.__len__()):
        if(vec[i][0] == letras):
            return i
    return -1


def printMatrix(v): 
        print("Empiezo")
        for i in range(v.__len__()): 
            for j in range (v[i].__len__()): 
                print("hash", i, " ", v[i][j])
            
        print("Done")


def calculaValor(boxes): 
    ret = 0
    for box in range(boxes.__len__()): 
        for element in range(boxes[box].__len__()): 
            retPequeño = 0
            retPequeño = retPequeño + box + 1
            retPequeño = retPequeño * (element + 1)
            retPequeño = retPequeño * int(boxes[box][element][1])
            ret = ret + retPequeño
    return ret



s = "your input"
cosas = s.split(",")#we divide the input into an array of substrings
boxes = []
for i in range(256): 
    newArray = []
    boxes.append(newArray)
for palabra in cosas:#for every word
    hash = 0 #the word's current value 
    codigo = ""
    for letra in range(palabra.__len__()):
        if(palabra[letra] != "=" and palabra[letra] != '-'):
            hash += ord(palabra[letra])
            hash = hash * 17
            hash = hash % 256
            codigo = codigo + palabra[letra]
        else: 
            if(palabra[letra] == "-"): 
                delVal = buscaEnVector(boxes[hash], codigo)
                if(delVal != -1):
                    boxes[hash].pop(delVal)
            else: 
                delVal = buscaEnVector(boxes[hash], codigo)
                if(delVal != -1):
                    boxes[hash][delVal] = (codigo, palabra[letra+1])
                else: 
                    boxes[hash].append((codigo, palabra[letra+1]))
    #printMatrix(boxes)
print("Total focusing power", calculaValor(boxes))
