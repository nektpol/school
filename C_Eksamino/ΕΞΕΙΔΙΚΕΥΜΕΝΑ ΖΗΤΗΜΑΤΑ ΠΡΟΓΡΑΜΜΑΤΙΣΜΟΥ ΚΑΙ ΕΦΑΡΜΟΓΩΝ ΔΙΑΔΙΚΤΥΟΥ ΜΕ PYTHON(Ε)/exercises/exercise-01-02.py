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

try:
    result = a / b
except ZeroDivisionError as error:
    print('Exception:', error)
else:
    print(f"The result: {a}/{b}={result}")