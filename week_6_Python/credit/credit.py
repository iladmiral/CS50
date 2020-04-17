# Get card number
print("Number : ", end='')
card = int(input())

# Get the lenght of
cardLen = len(str(card))
pair = 0
impair = 0
# Checksum the card
afterDigit = card

for i in range(cardLen):
    if i % 2 == 0:
        pair += afterDigit % 10
        afterDigit = int(afterDigit / 10)
    else:
        digitImpair = 0
        digitImpair = (afterDigit % 10) * 2
        if digitImpair >= 10:
            digitImpair = (digitImpair - 10) + 1
        impair += digitImpair
        afterDigit = int(afterDigit / 10)

# Verify the card
amex = (cardLen == 15) and (int(card / pow(10, cardLen - 2)) == 34 or int(card / pow(10, cardLen - 2)) == 37)

master = (cardLen == 16) and (int(card / pow(10, cardLen - 2)) == 51 or int(card / pow(10, cardLen - 2)) == 52
                              or int(card / pow(10, cardLen - 2)) == 53 or int(card / pow(10, cardLen - 2)) == 54 or int(card / pow(10, cardLen - 2)) == 55)
visa = (cardLen == 13 or cardLen == 14 or cardLen == 15 or cardLen == 16) and (int(card / pow(10, cardLen - 1)) == 4)

if (pair + impair) % 10 == 0 and amex:
    print("AMEX")
elif (pair + impair) % 10 == 0 and master:
    print("MASTERCARD")
elif (pair + impair) % 10 == 0 and visa:
    print("VISA")
else:
    print("INVALID")