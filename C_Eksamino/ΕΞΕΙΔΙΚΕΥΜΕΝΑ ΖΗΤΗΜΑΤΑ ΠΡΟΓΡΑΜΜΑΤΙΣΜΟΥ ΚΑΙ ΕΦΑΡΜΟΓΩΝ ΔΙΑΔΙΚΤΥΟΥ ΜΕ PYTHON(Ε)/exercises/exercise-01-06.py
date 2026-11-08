def Square(a):
    return a * a

mainLoop = True
while mainLoop:
    while True:
        try:
            a=int(input('Enter a number: '))
        except ValueError:
            print('Invalid input. Please enter an integer.')
            continue
        break

    if (a == 0):
        print('Exiting...')
        mainLoop = False
        break
    else:
        print('Square:', Square(a))