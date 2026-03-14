def bale_kena(my_sentence):
    my_result = ""
    for my_char in my_sentence :
        if my_char != " " :
            my_result += my_char
        else:
            my_result += "_"
    return my_result


def fere_10(my_sentence):
    if len(my_sentence)<=10:
        my_result = my_sentence
    else:
        my_result = ""
    for my_i in range(10):
        my_result += my_sentence[my_i]
    return my_result

def toCapital(my_word):
    capitalWord = ""
    for char in my_word:
        match char:
            case "a":
                capitalWord+="A"
            case "b":
                capitalWord+="B"
            case "c":
                capitalWord+="C"
            case "d":
                capitalWord+="D"
            case "e":
                capitalWord+="E"
            case _:
                capitalWord+="_"
    return capitalWord

 
my_s = input("String: ")
# my_s = bale_kena(my_s)
# my_s = fere_10(my_s)
my_s = toCapital(my_s)
print (my_s)