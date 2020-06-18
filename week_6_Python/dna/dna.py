from sys import argv, exit
import csv

# argv input
if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

# Open csv file
file = open(argv[1], "r")
csv_reader = csv.DictReader(file)

# Open sequences file
sequences = open(argv[2], "r")
content = sequences.read()

# Calculate the max sequence
STR = {'AGATC': 0, 'AATG': 0, 'TATC': 0}
STRKey = ['AGATC', 'AATG', 'TATC']

for s in range(3):
    maxSequ = 0
    for i in range(len(content)):
        j = i + len(STRKey[s])
        count = 0
        while content[i:j] == STRKey[s]:
            count += 1
            if count > maxSequ:
                maxSequ = count
            i = j
            j = j + len(STRKey[s])
    STR[STRKey[s]] = maxSequ
# Search for this sequence in csv database
for line in csv_reader:
    if line['AGATC'] == str(STR['AGATC']) and line['AATG'] == str(STR['AATG']) and line['TATC'] == str(STR['TATC']):
        print(line['name'])
        exit(0)
print("No match")