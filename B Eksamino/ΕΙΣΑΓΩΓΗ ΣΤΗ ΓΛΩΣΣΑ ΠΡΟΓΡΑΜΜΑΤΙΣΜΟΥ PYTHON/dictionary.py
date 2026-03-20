my_dictionary = {"1252": "A", "1253": "E", "1254": "I", "1255": "O", "1256": "U",
                 "1248": "a", "1249": "e", "1250": "i", "1251": "o", "1257": "u"}

for my_key in my_dictionary:
    print(my_key, ":", my_dictionary[my_key])
print("Search for key:")
print(my_dictionary[input()])

my_dictionary.pop("1252")  # Remove the key "1252" from the dictionary
print(my_dictionary)

