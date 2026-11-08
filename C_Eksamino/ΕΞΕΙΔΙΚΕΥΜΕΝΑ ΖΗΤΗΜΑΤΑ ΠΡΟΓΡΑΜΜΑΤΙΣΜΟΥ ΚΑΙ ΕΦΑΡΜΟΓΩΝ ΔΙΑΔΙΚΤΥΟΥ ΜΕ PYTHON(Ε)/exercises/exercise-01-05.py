def max(a, b):
    if a > b:
        return a
    else:
        return b

# main
while True:
    try:
        a=int(input('Enter the first number: '))
    except ValueError:
        print('Invalid input. Please enter an integer.')
        continue
    break
    
while True:
    try:
        b=int(input('Enter the second number: '))
    except ValueError:
        print('Invalid input. Please enter an integer.')
        continue
    break

print('The maximum is:', max(a, b))