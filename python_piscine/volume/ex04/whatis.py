import sys


def ErrorMessage(context):
    print("AssertionError:", context)


argc = len(sys.argv)

try:
    if argc == 1:
        sys.exit()
    elif argc > 2:
        raise AssertionError("more than one argument is provided")

    number = int(sys.argv[1])

    if (number % 2):
        print("I'm Odd.")
    elif (number % 2) == 0:
        print("I'm Even.")

except AssertionError as e:
    ErrorMessage(e)
except ValueError:
    ErrorMessage("argument is not an integer")
