from cs50 import get_int
while True:
    Height = get_int("Height : ")
    if Height > 0 and Height < 9:
        break

for i in range(Height):
    for j in range(Height + i + 3):
        if j >= Height - (i + 1) and j <= Height - 1:
            print("#", end='')
        elif j >= Height + 2 and j <= Height + (i + 2):
            print("#", end='')
        else:
            print(" ", end='')
    print("\n", end='')