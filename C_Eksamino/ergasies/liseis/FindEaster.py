while True:
    try:
        value = input("Give the year (0 to exit): ")
        EasterYear = int(value)

        if EasterYear < 0:
            raise ValueError

    except ValueError:
        print(value, "is invalid. Value must be a positive integer or 0.")
        continue

    if EasterYear == 0:
        break

    a = EasterYear % 19
    b = EasterYear % 4
    c = EasterYear % 7

    d = (a * 19 + 15) % 30
    e = (2 * b + 4 * c + 6 * d + 6) % 7

    EasterDay = d + e + 4
    EasterMonth = 4

    if EasterDay > 30:
        EasterDay -= 30
        EasterMonth = 5

    print(f"Orthodox Easter: {EasterDay:02d}/{EasterMonth:02d}/{EasterYear}")

print("Program terminated.")