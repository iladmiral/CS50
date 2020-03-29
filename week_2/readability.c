#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");
    int count_letters = 0;
    int count_words = 1;
    int count_Sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            count_letters++;
        }
        if (text[i] == ' ')
        {
            count_words++;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count_Sentences++;
        }
    }
    double L = (double)count_letters * 100 / (double)count_words;
    double S = (double)count_Sentences * 100 / (double)count_words;
    double index = 0.0588 * L - 0.296 * S - 15.8;
    if (index - (int)index >= 0.5)
    {
        index++;
        printf("Grade %i\n", (int)index);
    }
    else if (index < 1)
    {
        index = 1;
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)index);
    }

    return 0;
}