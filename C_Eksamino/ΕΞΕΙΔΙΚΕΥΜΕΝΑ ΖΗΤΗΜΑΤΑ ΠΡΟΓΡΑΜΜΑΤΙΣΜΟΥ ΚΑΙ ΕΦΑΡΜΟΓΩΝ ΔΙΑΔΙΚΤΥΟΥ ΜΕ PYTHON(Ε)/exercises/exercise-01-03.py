while True:
    i=int(input('Give an integer less than 10: '))
    try:
        if i not in range(0,10):
            raise ValueError
        elif i == 0:
           break
        else:
            a = 1
            while a<=10:
                print(f"{a}*{i}={a*i}")
                a+=1
    except ValueError:
        print(i,'is invalid.Value must be an integer less than 10')

    

    

