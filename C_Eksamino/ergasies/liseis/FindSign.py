
daysPerMonth = [31, 29, 31, 30, 31, 30,
                31, 31, 30, 31, 30, 31]

zodiacSigns = [
    "Capricorn", "Aquarius", "Pisces",
    "Aries", "Taurus", "Gemini",
    "Cancer", "Leo", "Virgo",
    "Libra", "Scorpio", "Sagittarius"
]

zodiacLimits = [
    20, 19, 20, 20, 20, 21,
    22, 22, 22, 23, 22, 21
]


while True:
    try:
        value = input("Give the month: ")
        month = int(value)

        if not 1 <= month <= 12:
            raise ValueError

        break

    except ValueError:
        print(value,'is invalid. Value must be an integer 1 to 12')

while True:
    try:
        value = input("Give the day: ")
        day = int(value)
        if not 1 <= day <= daysPerMonth[month - 1]:
            raise ValueError
        
        break
    except ValueError:
        print(value,'is invalid. Value must be a valid day for the selected month')



index = month - 1

if day > zodiacLimits[index]:
    index = (index + 1) % 12

print("Your Sign is:", zodiacSigns[index])