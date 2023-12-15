'''
if u prefer
f = open("input15.txt")
s = f.read()
'''
s = "your_input_here" 
cosas = s.split(",")#we divide the input into an array of substrings
retFinal = 0 #our return value 
for palabra in cosas:#for every word
    ret = 0 #the word's current value 
    for letra in palabra:
        ret = ret + ord(letra) #get ascii value 
        ret = ret * 17 
        ret = ret % 256 #execute hash function
    #print("iteracion acabada")
    #print(ret)
    retFinal = retFinal + ret #add current value to return value 
print(retFinal) #print solution 
