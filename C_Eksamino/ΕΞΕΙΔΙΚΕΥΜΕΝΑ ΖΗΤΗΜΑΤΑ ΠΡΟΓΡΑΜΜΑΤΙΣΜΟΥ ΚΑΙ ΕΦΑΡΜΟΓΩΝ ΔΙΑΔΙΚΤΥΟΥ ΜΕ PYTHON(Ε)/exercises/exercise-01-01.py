loop = True
while loop:
    try:
        NumberId = int(input('Give NumberId: '))
    except ValueError:
        print('Invalid input. Please enter a Valid NumberId.')
        continue
    loop = False
    print('NumberId is valid')