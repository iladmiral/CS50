from sys import argv, exit
from cs50 import SQL

# Connect with database
db = SQL("sqlite:///students.db")

# Check correct argument
if len(argv) != 2:
    print("Please enter correct Input")
    exit(1)

file = list(db.execute("SELECT first, middle, last, birth  FROM students WHERE house = (?) ORDER BY last, first", argv[1]))

# Slecting first, middle, last, birth of house
for row in file:
    if row['middle'] == None:
        print(row['first'], row['last'], end='')
        print(", born ", end='')
        print(row['birth'])
    else:
        print(row['first'], row['middle'], row['last'], end='')
        print(", born ", end='')
        print(row['birth'])
