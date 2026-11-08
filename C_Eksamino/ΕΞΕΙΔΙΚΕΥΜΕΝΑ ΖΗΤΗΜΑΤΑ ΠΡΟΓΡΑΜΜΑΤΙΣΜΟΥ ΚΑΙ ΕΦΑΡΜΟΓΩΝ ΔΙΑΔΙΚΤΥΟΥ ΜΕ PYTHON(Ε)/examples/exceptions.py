# Example of handling exceptions in Python with try, except, and finally blocks
# finally block will always execute, regardless of exceptions
# finally is not mandatory

# try:
#     D = {'a':1,'b':2,'c':3}
#     s = input('Give letter: ')
#     print(D[s])
# except ValueError:
#     print('Invalid value given')
# except KeyError: 
#     print('Invalid key given')
# except: # Catch any other unexpected exceptions
#     print('An unexpected error occurred')
# finally:
#     print('Finaly\nOut of try')



# # Multiple errors can be used with one except
# try:
#     L=[1,2,3]
#     x=int(input('Give position: '))
#     print(L[x])
# except (ValueError, IndexError):
#     print('Invalid input, try again')

# raise is used to manually trigger an exception
# Example:
# raise ValueError
# raise NameError('This is a manually raised NameError')

# i=int(input('Give an integer less than 10: '))
# try:
#     if i >10:
#         raise ValueError
#     else:
#         print('Value',i,'is valid')
# except ValueError:
#     print(i,'is invalid.Value must be less than 10')

# # Example of handling multiple exceptions with specific error messages
# try:
#     L=[1,2,3]
#     x=int(input('Give position: '))
#     print(L[x])
# except IndexError as error:
#     print('Invalid input, try again:', error)
# except ValueError as error: 
#     print('Invalid input, try again:', error)

# # pass is used to indicate an empty block of code, it does nothing and allows the program to continue execution
# a=0
# div=0
# try:
#     div = 23 / a
# except:
#     pass
# print('Value of div is', div)


    