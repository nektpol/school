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
            case "f":
                capitalWord+="F"
            case "g":
                capitalWord+="G"
            case "h":
                capitalWord+="H"
            case "i":
                capitalWord+="I"
            case "j":
                capitalWord+="J"
            case "k":
                capitalWord+="K"
            case "l":
                capitalWord+="L"
            case "m":
                capitalWord+="M"
            case "n":
                capitalWord+="N"
            case "o":
                capitalWord+="O"
            case "p":
                capitalWord+="P"
            case "q":
                capitalWord+="Q"
            case "r":
                capitalWord+="R"
            case "s":
                capitalWord+="S"
            case "t":
                capitalWord+="T"
            case "u":
                capitalWord+="U"
            case "v":
                capitalWord+="V"
            case "w":
                capitalWord+="W"
            case "x":
                capitalWord+="X"
            case "y":
                capitalWord+="Y"
            case "z":
                capitalWord+="Z"
            case _:
                capitalWord+="_"
    return capitalWord

 
my_s = input("String: ")
# my_s = bale_kena(my_s)
# my_s = fere_10(my_s)
my_s = toCapital(my_s)
print (my_s)