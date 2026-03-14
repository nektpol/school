def bale_kena(my_sentence):
    my_result = ""
    for char in my_sentence :
        if char != " ":
            my_result += char
        else:
            my_result += "+"
    return my_result

def fere_10(my_sentence):
    if len(my_sentence)<=10:
        my_result = my_sentence
    else:
        my_result = ""
    for i in range(10):
        my_result += my_sentence[i]
    return my_result



my_s = input("String: ")
my_s = bale_kena(my_s)
my_s = fere_10(my_s)
print (my_s)

print ("------------------")
for it in range(4):
    print (it)

print ("------------------")
for it in range(4):
    it = it + 1
    print (it)

print ("------------------")
for it in range(4):
    it *= 2
    print (it)

print ("------------------")
for it in range(4):
    it = it ** 2
    print (it)

print ("------------------")
sum = 0
for it in range(4):
    sum += it
    print (it," ",sum)