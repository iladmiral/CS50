#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Prompt for input
    long cardID = get_long("Number : ");
    //Count lenght
    long forCount = cardID;
    int len = 0;
    while (forCount != 0)
    {
        forCount = forCount / 10;
        len++;
    }
    long afterDigit = cardID;
    int pair = 0;
    int impair = 0;
    // Checksum for card
    for (int i = 0; i < len; i++)
    {
        if (i % 2 == 0)
        {
            pair += afterDigit % 10;
            afterDigit = afterDigit / 10;
        }
        else
        {
            int digitImpair = 0;
            digitImpair = (afterDigit % 10) * 2;
            if (digitImpair >= 10)
            {
                digitImpair = (digitImpair - 10) + 1;
            }
            impair += digitImpair;
            afterDigit = afterDigit / 10;
        }
    }

    // verify the card
    long twoDigit = pow(10, len - 2);
    long oneDigit = pow(10, len - 1);
    bool american = (len == 15) && (cardID / twoDigit == 34 || cardID / twoDigit == 37);
    bool master = (len == 16) && (cardID / twoDigit == 51 || cardID / twoDigit == 52 || cardID / twoDigit == 53
                                  || cardID / twoDigit == 54 || cardID / twoDigit == 55);
    bool visa = (len == 13 || len == 14 || len == 15 || len == 16) && (cardID / oneDigit == 4);
    
    if ((pair + impair) % 10 == 0 && american)
    {
        printf("AMEX\n");
    }
    else if ((pair + impair) % 10 == 0 && visa)
    {
        printf("VISA\n");
    }
    else if ((pair + impair) % 10 == 0 && master)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}
