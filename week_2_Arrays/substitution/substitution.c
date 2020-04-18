#include <cs50.h>
#include <stdio.h>
#include <string.h>

int VerifyLenght(string s[]);
int verifyAlphabitic(string s[], int i);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (VerifyLenght(argv) == 0)  // Verify the lenght
        {
            for (int i = 0; i < 26; i++)
            {
                if (verifyAlphabitic(argv, i) == 1) // Verify alphabitic
                {
                    return 1;

                }
                else if (verifyAlphabitic(argv, i) == 0)
                {
                    for (int j = i + 1; j < 26; j++)
                    {
                        if (argv[1][i] == argv[1][j] || argv[1][i] == argv[1][j] - 32 || argv[1][i] == argv[1][j] + 32) // Verify the reapeted char
                        {
                            printf("Error Key! \n");
                            return 1;
                        }
                    }
                }
            }
        string plaintext = get_string("plaintext: ");
        char lowercase[26];
        char uppercase[26];
        for (int l=0; l < 26; l++)
        {
            lowercase[l] = 'a' + l;
            uppercase[l] = 'A' + l;
        }
        for (int n=0; n < strlen(plaintext); n++)
        {
            for (int m=0; m < 26; m++)
            {

                if (plaintext[n] == lowercase[m])
                {
                    if (argv[1][m] <= 'Z' && argv[1][m] >= 'A')
                    {
                        plaintext[n] = argv[1][m]+32;
                        break;
                    }
                    else
                    {
                        plaintext[n] = argv[1][m];
                        break;
                    }
                }
                if (plaintext[n] == uppercase[m])
                {
                    if (argv[1][m] <= 'z' && argv[1][m] >= 'a')
                    {
                        plaintext[n] = argv[1][m]-32;
                        break;
                    }
                    else
                    {
                        plaintext[n] = argv[1][m];
                        break;
                    }

                }
            }

        }
        printf("ciphertext: %s\n", plaintext);
        return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

int verifyAlphabitic(string s[], int i)
{
    if ((s[1][i] >= 'a' && s[1][i] <= 'z') || (s[1][i] >= 'A' && s[1][i] <= 'Z'))
    {
        return 0;
    }
    else
    {
        printf("Key must contain 26 just a characters.\n");
        return 1;
    }
}

int VerifyLenght(string s[])
{
    if (strlen(s[1]) == 26)
    {
        return 0;
    }
    else
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
}
