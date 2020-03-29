#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int Height;
    do
    {
        Height = get_int("Height: ");
    }
    while (Height <= 0 || Height > 8);

    for (int i = 0; i < Height; i++)
    {
        for (int j = 0; j < Height + (i + 3); j++)
        {
            if (j >= Height - (i + 1) && j <= Height - 1)
            {
                printf("#");
            }
            else if (j >= Height + 2 && j <= Height + (i + 2))
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
