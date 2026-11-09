import math

print('Program To Find Area Of A Circle')
print('-------------------------------')

while True:
    try:
        radius = float(input('Input value radius circle: '))
    except ValueError:
        print('Invalid input. Please enter a Valid number.')
        continue
    if radius <= 0:
        print('Invalid input. Please enter a positive number.')
        continue
    break

area = math.pi * radius ** 2
print(f'Area of the circle is: {area:.3f}')
