def isOdd(num):
    return num % 2 != 0

def mo(arr):
    sum = 0
    for num in arr:
        sum += num
    return sum / len(arr)

def doseTimi():
    return int(input("Dose timi: "))

numbers = [doseTimi() for _ in range(10)]
print("Pin:", numbers)
print("Average:", mo(numbers))
print("Odd numbers:", [num for num in numbers if isOdd(num)])

z = numbers[-1]
numbers[-1] = numbers[0]
numbers[0] = z
print("Pin after swap:", numbers)