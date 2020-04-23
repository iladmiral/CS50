from sys import argv, exit
from cs50 import SQL
import csv

# Connect with database
db = SQL("sqlite:///students.db")

# Check correct argument
if len(argv) != 3:
    print("Please enter correct Input")
    exit(1)

# Open csv file
with open(argv[1], "r") as file:
    reader = csv.DictReader(file)

# Inserting data into students table
    for row in reader:
        house = row['house']
        birth = row['birth']
        name = row['name'].split()
        first = name[0]
        if len(name) == 3:
            middle = name[1]
            last = name[2]
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                       first, middle, last, house, birth)
        else:
            last = name[1]
            db.execute("INSERT INTO students (first, last, house, birth) VALUES (?, ?, ?, ?)", first, last, house, birth)

