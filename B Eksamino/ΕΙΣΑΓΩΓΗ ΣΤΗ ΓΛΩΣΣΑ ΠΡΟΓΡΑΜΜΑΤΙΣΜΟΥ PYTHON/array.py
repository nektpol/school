def doseTimi():
    return int(input("Dose timi: "))

pin = []
for i in range(10):
    pin.append(doseTimi())

print("Pin:", pin)