while True:
    try:
        amount=float(input("Give the amount:"))
        break
    except ValueError:
        print("Amount must be float number")

while True:
    try:
        years=int(input("Give years:"))
    except ValueError:
        print("Years must be integer")
