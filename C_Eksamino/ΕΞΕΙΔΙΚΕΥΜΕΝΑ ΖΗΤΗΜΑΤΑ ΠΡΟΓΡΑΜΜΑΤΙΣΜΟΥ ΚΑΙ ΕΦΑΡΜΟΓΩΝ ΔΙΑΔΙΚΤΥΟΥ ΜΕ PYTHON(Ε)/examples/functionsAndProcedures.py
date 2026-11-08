# Functions 
def add(a, b):
    return a + b

def subtract(a, b):
    return a - b

# Procedurs
def print_message(message):
    print(message)

def print_error(message):
    print('Error:', message)

# Global variables
def example():
    global globalVar
    print('Global variable:', globalVar) # It will print what you type
    globalVar = 'Tom'

globalVar = input('Enter your Name: ')
example()
print(globalVar) # It will print 'Tom' because the global variable was modified inside the example() function

# How to use the functions
variable = add(5,3)
print(variable) # It will print 8

variable = subtract(5,3)
print(variable) # It will print 2

# How to use the procedures
print_message('Hello, World!') # It will print 'Hello, World!'
print_error('Something went wrong!') # It will print 'Error: Something went wrong!'

def print_me(str = ''):
    print(str)

print_me('Hello!') # It will print 'Hello!'
print_me() # It will print an empty line because the default value of the parameter is an empty string

def print_me2(str):
    print(str)

print_me2('Hello again!') # It will print 'Hello again!'
print_me2() # It will raise an error because the parameter is required

